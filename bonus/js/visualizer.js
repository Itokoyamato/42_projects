var scene, camera, renderer, controls;
var geometry, material, mesh;
var rooms = [];
var tunnels = [];
var ants = [];

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
var skybox;
var ant_object;
var isRunning = false;

window.onload = function() {
	var loader = new THREE.OBJLoader();
	loader.load("fire-ant-1.obj",
		function ( object ) {
			object.traverse( function ( child ) {
				if ( child instanceof THREE.Mesh )
					child.material.color.setHex(0x151515);
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
	for (i in rooms)
		scene.remove(rooms[i].object);
	for (i in tunnels)
		scene.remove(tunnels[i].object);
	for (i in ants)
		scene.remove(ants[i].object);
	document.getElementById("fileToLoad").value = "";
	rooms = [];
	tunnels = [];
	ants = [];
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
	// controls.getObject().position.set(2, 2, 0);
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

function parse_data(data)
{
	var lines = data.split("\n");
	for (var i = 0; i < lines.length; i++)
	{
		var l = lines[i];
		if (i == 0)
		{
			// Ants processing
		}
		else
		{
			if (l.includes("#") || l.includes("##"))
			{

			}
			else if (l.includes("-"))
			{
				var split = l.split("-");
				var room1;
				var room2;
				for (var j = 0; j < rooms.length; j++)
				{
					if (rooms[j].name == split[0])
						room1 = rooms[j];
					if (rooms[j].name == split[1])
						room2 = rooms[j];
				}
				if (room1 && room2)
					addTunnel(room1, room2);
			}
			else
			{
				var split = l.split(" ");
				addRoom(parseInt(split[1]), parseInt(split[2]), split[0]);
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

	var light = new THREE.PointLight(0xffffff, 1, 100);
	light.position.set(0, 10, 0);
	scene.add( light );

	var light = new THREE.AmbientLight(0x404040, 2);
	scene.add( light );

	var geometry = new THREE.SphereGeometry(100, 124, 124);
	var texture = new THREE.TextureLoader().load("skybox.jpg");
	var material = new THREE.MeshPhongMaterial({color: 0xffffff, map: texture})
	skybox = new THREE.Mesh(geometry, material);
	skybox.material.side = THREE.DoubleSide;
	scene.add(skybox);

	controls = new THREE.PointerLockControls(camera);
	controls.getObject().position.set(10, 7, 40);
	// controls.getObject().position.set(2, 2, 0);
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
	renderer.setSize(element.clientWidth - 20, element.clientHeight, false);

	element.appendChild(renderer.domElement);
}

delta_amount = 100.0;
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

		if ( moveForward || moveBackward ) velocity.z -= direction.z * (delta_amount) * delta;
		if ( moveLeft || moveRight ) velocity.x -= direction.x * delta_amount * delta;
		if (moveForward) velocity.y += direction3d.y * delta_amount * delta;
		if (moveBackward) velocity.y -= direction3d.y * delta_amount * delta;

		controls.getObject().translateX( velocity.x * delta );
		controls.getObject().translateZ( velocity.z * delta );
		controls.getObject().translateY( velocity.y * delta );
		prevTime = time;

		raycaster.set( camera.getWorldPosition(), camera.getWorldDirection() );
		var intersects = raycaster.intersectObjects( scene.children );
		var info = document.getElementById("info_content");
		if (intersects[0])
		{
			if (skybox === intersects[0].object)
				info.innerHTML = "";
			for (i in rooms)
			{
				if (rooms[i].object === intersects[0].object)
					info.innerHTML = "Room: " + rooms[i].name + "<br>" + "Ants: " + rooms[i].ants;
			}
			for (i in tunnels)
			{
				if (tunnels[i].object === intersects[0].object)
					info.innerHTML = "Tunnel: " + tunnels[i].name + "<br>" + "Ants: " + tunnels[i].ants;
			}
		}
		else
			info.innerHTML = "";
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
	var geometry = new THREE.CylinderGeometry(0.1, 0.1, direction.length(), 8, 1);
	var texture = new THREE.TextureLoader().load("skybox.jpg");
	texture.wrapS = texture.wrapT = THREE.RepeatWrapping;
	texture.repeat.set(2 * Math.PI * 0.1 / direction.length(), 2);
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
	var room = new THREE.BoxGeometry(1, 0.5, 1);
	var material = new THREE.MeshLambertMaterial({color: 0xff0000});

	var mesh = new THREE.Mesh(room, material);
	var z = Math.floor(Math.random() * 10);
	mesh.position.set(x, z, y);
	scene.add(mesh);
	room = {object: mesh, name: name, ants: ants};
	rooms.push(room);
	addAnt(x, z + 0.2, y + 0.2);
	return (room);
}

function toRadians(angle)
{
	return (angle * (Math.PI / 180));
}

function addAnt(x, y, z)
{
	var ant = ant_object.clone();
	ant.scale.set(0.5,0.5,0.5);
	ant.position.set(x, y, z);
	scene.add(ant);
	var ant = {object: ant};
	ants.push(ant);
}

function addTunnel(room1, room2, ants)
{
	var tunnel = new THREE.CylinderGeometry( 0.1, 0.1, 10);
	var material = new THREE.MeshLambertMaterial({color: 0xffffff});

	var mesh = new cylinderMesh(room1.object.position, room2.object.position, material);
	scene.add(mesh);
	tunnel = {object: mesh, name: room1.name + "-" + room2.name, ants: ants};
	tunnels.push(tunnel);
	return (tunnel);
}