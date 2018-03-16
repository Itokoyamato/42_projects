var camera_speed = 100.0;
var turn_speed = 1000;

var scene, camera, renderer, controls;
var geometry, material, mesh;

var isRunning = false;
var arr_rooms = [];
var arr_rooms_obj = [];
var arr_tunnels = [];
var arr_ants = [];
var arr_turns = [];
var start_room;
var end_room;
var current_turn = -1;
var ant_count = 0;
var room_count = 0;
var	turn_startTime;
var	state = "stopped";
var play_interval;

var instructions = document.getElementById( 'instructions' );
var havePointerLock = 'pointerLockElement' in document || 'mozPointerLockElement' in document || 'webkitPointerLockElement' in document;

var controlsEnabled = false;
var moveForward = false;
var moveBackward = false;
var moveLeft = false;
var moveRight = false;
var prevTime = performance.now();
var velocity = new THREE.Vector3();
var direction = new THREE.Vector3();
var raycaster = new THREE.Raycaster();
var last_raycast = performance.now();

var skybox;
var texture_dirt;
var texture_glow;
var ant_object;
var ant_material = new THREE.MeshLambertMaterial({ color: 0xFF0000, opacity: 1});

function changeTurnSpeed(element)
{
	turn_speed = 200*(element.value);
}

function changeCameraSpeed(element)
{
	camera_speed = 100*(element.value);
}

function stop()
{
	state = "stopped";
	if (play_interval)
	{
		clearInterval(play_interval);
		play_interval = null;
	}
	current_turn = -1;
	for (i in arr_ants)
	{
		scene.remove(arr_ants[i].object);
		arr_ants[i].object = createAnt(start_room.object.position.x, start_room.object.position.y, start_room.object.position.z);
		arr_ants[i].room = start_room;
	}
}

function play()
{
	state = "play";
	if (play_interval)
		return;
	play_interval = setInterval(function()
	{
		var wait = false;
		if (state == "play")
		{
			for (i in arr_ants)
			{
				if (arr_ants[i].moving)
					wait = true;
			}
			if (!wait)
				next_move();
		}
	}, 100);
}

function pause()
{
	state = "paused";
	if (play_interval)
	{
		clearInterval(play_interval);
		play_interval = null;
	}
}

function next_move(isManual)
{
	if (isManual && state == "play")
		return;
	current_turn++;
	var turn = arr_turns[current_turn];
	if (turn)
	{
		for (i in turn)
		{
			var move = turn[i];
			move.ant.moving = true;
			move.ant.dest = move.dest;
			turn_startTime = performance.now();
			move.ant.object.lookAt(move.ant.dest.object.position);
		}
	}
	else
		pause();
}

window.onload = function() {
	var loader = new THREE.OBJLoader();
	loader.load("fire-ant-1.obj",
		function ( object ) {
			object.traverse( function ( child ) {
				if ( child instanceof THREE.Mesh )
				{
					child.material = ant_material;
					child.geometry.applyMatrix(new THREE.Matrix4().makeRotationY(toRadians(-90)));
					child.geometry.applyMatrix(new THREE.Matrix4().makeTranslation(-0.2, 0.1, 0));
				}
			});
			ant_object = object;
		},
		function ( xhr ) {
			console.log( ( xhr.loaded / xhr.total * 100 ) + '% loaded' );
		},
		function ( error ) {
			console.log("An error happened while loading model");
		}
	);
	init();
	animate();
}

function reset_scene()
{
	stop();
	for (i in arr_rooms)
		scene.remove(arr_rooms[i].object);
	for (i in arr_tunnels)
		scene.remove(arr_tunnels[i].object);
	for (i in arr_ants)
		scene.remove(arr_ants[i].object);
	document.getElementById("fileToLoad").value = "";
	arr_rooms = [];
	arr_tunnels = [];
	arr_ants = [];
	arr_turns = [];
	start_room = null;
	end_room = null;
	ant_count = 0;
	current_turn = -1;
	document.getElementById("result").innerHTML = "";
	moveForward = false;
	moveBackward = false;
	moveLeft = false;
	moveRight = false;
	prevTime = performance.now();
	velocity = new THREE.Vector3();
	direction = new THREE.Vector3();
	controls = new THREE.PointerLockControls(camera);
	controls.getObject().position.set(10, 7, 40);
	scene.add(controls.getObject());
	isRunning = false;
}

function loadFileAsText(element){
	var fileToLoad = element.files[0];

	var fileReader = new FileReader();
	fileReader.onload = function(fileLoadedEvent){
		var data = fileLoadedEvent.target.result;
		reset_scene();
		setTimeout(function(){
			isRunning = true;
			document.getElementById("result").innerHTML = data;
			parse_data(data);
		}, 500);
	};

	fileReader.readAsText(fileToLoad, "UTF-8");
}

var start_end = 0;
function parse_data(data)
{
	var lines = data.split("\n");
	for (var i = 0; i < lines.length; i++)
	{
		var l = lines[i];
		if (i == 0)
			ant_count = parseInt(l);
		else
		{
			if (l.includes("#") || l.includes("##"))
			{
				if (l.includes("##start"))
					start_end = 1;
				if (l.includes("##end"))
					start_end = 2;
			}
			else if (l.includes("L"))
			{
				var moves = [];
				var split = l.split(" ");
				for (j in split)
				{
					if (split[j] == "")
						continue;
					var split2 = split[j].replace("L", "").split("-");
					var result = arr_rooms.filter(function(obj) {return obj.name == split2[1].trim();});
					moves.push({ant: arr_ants[split2[0]-1], dest: result[0]});
				}
				arr_turns.push(moves);
			}
			else if (l.includes("-"))
			{
				var split = l.split("-");
				var room1;
				var room2;
				for (var j = 0; j < arr_rooms.length; j++)
				{
					if (arr_rooms[j].name == split[0].trim())
						room1 = arr_rooms[j];
					if (arr_rooms[j].name == split[1].trim())
						room2 = arr_rooms[j];
				}
				if (room1 && room2)
					addTunnel(room1, room2);
			}
			else
			{
				var split = l.split(" ");
				room_count++;
				addRoom(parseInt(split[1])*5, parseInt(split[2])*5, split[0].trim());
			}
		}
	}
}

function init() {
	if ( havePointerLock ) {
		var element = document.body;
		var pointerlockchange = function ( event ) {
			if ( document.pointerLockElement === element || document.mozPointerLockElement === element || document.webkitPointerLockElement === element ) {
				moveForward = false;
				moveBackward = false;
				moveLeft = false;
				moveRight = false;
				velocity = new THREE.Vector3();
				controlsEnabled = true;
				controls.enabled = true;
				blocker.style.display = 'none';
			} else {
				controls.enabled = false;
				blocker.style.display = 'block';
				instructions.style.display = '';
			}
		};
		var pointerlockerror = function ( event ) {
			instructions.style.display = '';
		};
		// Hook pointer lock state change events
		document.addEventListener( 'pointerlockchange', pointerlockchange, false );
		document.addEventListener( 'mozpointerlockchange', pointerlockchange, false );
		document.addEventListener( 'webkitpointerlockchange', pointerlockchange, false );
		document.addEventListener( 'pointerlockerror', pointerlockerror, false );
		document.addEventListener( 'mozpointerlockerror', pointerlockerror, false );
		document.addEventListener( 'webkitpointerlockerror', pointerlockerror, false );
		instructions.addEventListener( 'click', function ( event ) {
			instructions.style.display = 'none';
			// Ask the browser to lock the pointer
			element.requestPointerLock = element.requestPointerLock || element.mozRequestPointerLock || element.webkitRequestPointerLock;
			element.requestPointerLock();
		}, false );
		blocker.style.display = "block";
	} else {
		instructions.innerHTML = 'Your browser doesn\'t seem to support Pointer Lock API';
	}
	var element = document.getElementById("main_div");

	scene = new THREE.Scene();
	camera = new THREE.PerspectiveCamera(75, element.offsetWidth / element.offsetHeight, 1, 10000);

	// var light = new THREE.PointLight(0xffffff, 1, 100);
	// light.position.set(10, 10, 10);
	// scene.add( light );

	// light = new THREE.PointLight(0xffffff, 1, 100);
	// light.position.set(-10, 10, 10);
	// scene.add( light );

	var light = new THREE.AmbientLight(0x404040, 4);
	scene.add( light );

	var geometry = new THREE.SphereGeometry(1000, 32, 32);
	texture_dirt = new THREE.TextureLoader().load("skybox.jpg");
	var material = new THREE.MeshPhongMaterial({color: 0xffffff, map: texture_dirt, transparent: true, opacity: 0.3})
	skybox = new THREE.Mesh(geometry, material);
	skybox.material.side = THREE.DoubleSide;
	scene.add(skybox);

	texture_glow = new THREE.TextureLoader().load("glow.png");

	controls = new THREE.PointerLockControls(camera);
	controls.getObject().position.set(10, 7, 40);
	scene.add(controls.getObject());

	var onKeyDown = function ( event ) {
		switch ( event.keyCode ) {
			case 38: // up
			case 87: // w
				moveForward = true;
				break;
			case 37: // left
			case 65: // a
				moveLeft = true; break;
			case 40: // down
			case 83: // s
				moveBackward = true;
				break;
			case 39: // right
			case 68: // d
				moveRight = true;
				break;
			case 32: // space
				if ( canJump === true ) velocity.y += 350;
				canJump = false;
				break;
		}
	};
	var onKeyUp = function ( event ) {
		switch( event.keyCode ) {
			case 38: // up
			case 87: // w
				moveForward = false;
				break;
			case 37: // left
			case 65: // a
				moveLeft = false;
				break;
			case 40: // down
			case 83: // s
				moveBackward = false;
				break;
			case 39: // right
			case 68: // d
				moveRight = false;
				break;
		}
	};
	document.addEventListener('keydown', onKeyDown, false);
	document.addEventListener('keyup', onKeyUp, false);

	renderer = new THREE.WebGLRenderer();
	renderer.setSize(element.clientWidth, element.clientHeight, false);

	element.appendChild(renderer.domElement);
}

function animate()
{
	requestAnimationFrame(animate);
	if (controlsEnabled === true && controls.enabled === true)
	{
		var time = performance.now();
		var delta = ( time - prevTime ) / 1000;
		var direction3d = new THREE.Vector3();
		direction3d.normalize();
		controls.getDirection(direction3d);

		velocity.x -= velocity.x * 10.0 * delta;
		velocity.z -= velocity.z * 10.0 * delta;
		velocity.y -= velocity.y * 10.0 * delta;
		direction.z = Number(moveForward) - Number(moveBackward);
		direction.x = Number(moveLeft) - Number(moveRight);
		direction.y = Number(moveForward) - Number(moveBackward);
		direction.normalize();

		if ( moveForward || moveBackward ) velocity.z -= direction.z * (camera_speed) * delta;
		if ( moveLeft || moveRight ) velocity.x -= direction.x * camera_speed * delta;
		if (moveForward) velocity.y += direction3d.y * camera_speed * delta;
		if (moveBackward) velocity.y -= direction3d.y * camera_speed * delta;

		controls.getObject().translateX( velocity.x * delta );
		controls.getObject().translateZ( velocity.z * delta );
		controls.getObject().translateY( velocity.y * delta );
		prevTime = time;

		if (time - last_raycast > 100)
		{
			raycaster.set( camera.getWorldPosition(), camera.getWorldDirection() );
			var intersects = raycaster.intersectObjects(arr_rooms_obj);
			var info = document.getElementById("info_content");
			if (intersects[0])
			{
				if (skybox === intersects[0].object)
					info.innerHTML = "";
				for (i in arr_rooms)
				{
					if (arr_rooms[i].object === intersects[0].object)
						info.innerHTML = "Room: " + arr_rooms[i].name;
				}
			}
			else
				info.innerHTML = "";
			last_raycast = time;
		}
	}
	for (i in arr_ants)
	{
		var ant = arr_ants[i];
		if (ant.moving)
		{
			var tmp = new THREE.Vector3();
			var	dest = ant.room.object.position.clone();
			var progress = Math.min((performance.now() - turn_startTime) / turn_speed);

			dest.z += 0.5;
			dest.y -= 0.5;
			tmp.copy(ant.dest.object.position).sub(ant.room.object.position).multiplyScalar(progress);
			ant.object.position.copy(dest).add(tmp);
			if (progress >= 1)
			{
				ant.moving = false;
				ant.room = ant.dest;
				ant.object.position.set(ant.dest.object.position.x, ant.dest.object.position.y - 0.5, ant.dest.object.position.z + 0.5);
				ant.dest = null;
			}
		}
	}
	renderer.render(scene, camera);
}

function cylinderMesh(pointX, pointY, material) {
	var direction = new THREE.Vector3().subVectors(pointY, pointX);
	var orientation = new THREE.Matrix4();
	orientation.lookAt(pointX, pointY, new THREE.Object3D().up);
	orientation.multiply(new THREE.Matrix4().set(1, 0, 0, 0,
		0, 0, 1, 0,
		0, -1, 0, 0,
		0, 0, 0, 1));
	var geometry = new THREE.CylinderGeometry(1.5, 1.5, direction.length() - 5, 8, 1, true);
	var texture = texture_dirt.clone();
	texture.needsUpdate = true;
	texture.wrapS = texture.wrapT = THREE.RepeatWrapping;
	texture.repeat.set(20 * Math.PI * 0.1 / direction.length(), 1);
	material.map = texture;
	var mesh = new THREE.Mesh(geometry, material);
	mesh.applyMatrix(orientation);
	mesh.position.x = (pointY.x + pointX.x) / 2;
	mesh.position.y = (pointY.y + pointX.y) / 2;
	mesh.position.z = (pointY.z + pointX.z) / 2;
	return mesh;
}

function addRoom(x, y, name, ants)
{
	var room = new THREE.SphereGeometry(3, 16, 16);
	var material = new THREE.MeshLambertMaterial({transparent: true, opacity: 0.7});

	var mesh = new THREE.Mesh(room, material);
	var z = Math.floor(Math.random() * 50);
	if (document.getElementById("randomPos").checked == true)
	{
		x = x + Math.floor(Math.random() * 50);
		y = y + Math.floor(Math.random() * 50);
	}
	mesh.position.set(x, z, y);
	material.map = texture_dirt;
	scene.add(mesh);
	room = {object: mesh, name: name, ants: ants};
	arr_rooms.push(room);
	arr_rooms_obj.push(mesh);
	if (start_end == 1)
	{
		start_room = room;
		start_end = 0;
		for (var j = 1; j <= ant_count; j++)
		{
			addAnt(x, z, y, room);
		}
	}
	if (start_end == 2)
	{
		end_room = room;
		start_end = 0;
	}
	return (room);
}

function toRadians(angle)
{
	return (angle * (Math.PI / 180));
}

function createAnt(x, y, z)
{
	var ant = ant_object.clone();
	ant.position.set(x - 0.6, y, z);
	scene.add(ant);
	return (ant);
}

function addAnt(x, y, z, room)
{
	var ant = createAnt(x, y, z);

	ant = {object: ant, room: room};
	arr_ants.push(ant);
}

function addTunnel(room1, room2, ants)
{
	var tunnel = new THREE.CylinderGeometry(0.1, 0.1, 10);
	var material = new THREE.MeshLambertMaterial({color: 0xffffff, transparent: true, opacity: 0.7});

	var mesh = new cylinderMesh(room1.object.position, room2.object.position, material);
	scene.add(mesh);
	tunnel = {object: mesh, name: room1.name + "-" + room2.name, ants: ants};
	arr_tunnels.push(tunnel);
	return (tunnel);
}