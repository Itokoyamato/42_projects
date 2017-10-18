<?php
	include_once "./account.php";
	if ($account->isLoggedIn()['error'])
		header("Location: ./");
	else
	{
		include_once "./header.php";
		?>
		<div class="main-container">
			<img id="photo" alt="The screen capture will appear in this box.">
			<div class="container camera-container" id="camera-container">
				<div class="stickers-canvas" id="stickers-canvas"></div>
				<video class="camera" autoplay></video>
			</div>
			<div class="container sidebar">
				<div class="container title">Your gallery</div>
			</div>
			<div class="container take-picture" onclick="takepicture()">click</div>
			<div class="container stickers-container">
				<img class="sticker" src="./img/stickers/grumpy.png" onclick="javascript:newSticker('grumpy.png')">
				<img class="sticker" src="./img/stickers/nanachi.png" onclick="javascript:newSticker('nanachi.png')">
				<img class="sticker" src="./img/stickers/kebab.png" onclick="javascript:newSticker('kebab.png')">
			</div>
		</div>
		<script>
			var video = document.querySelector("video");
			var localMediaStream = null;
			var width = 480;
			var height = 0;

			function takepicture() {
				var canvas = document.createElement("canvas");
				var context = canvas.getContext("2d");
				height = video.videoHeight / (video.videoWidth / width);
				canvas.width = video.clientWidth;
				canvas.height = video.clientHeight;
				context.drawImage(video, 0, 0, video.clientWidth, video.clientHeight);

				var data = canvas.toDataURL('image/png');
				document.getElementById("photo").setAttribute('src', data);

				var stickers_send = JSON.parse(JSON.stringify(stickers));
				// for (i in stickers_send)
				// {
				// 	var sticker = stickers_send[i];
				// 	var corners = getPixelsByAngle(sticker.x, sticker.y, sticker.width/2, sticker.height/2, sticker.rot);
				// 	var x = video.clientWidth;
				// 	var y = video.clientHeight;
				// 	for (j in corners)
				// 	{
				// 		if (corners[j][0] < x)
				// 			x = corners[j][0];
				// 		if (corners[j][1] < y)
				// 			y = corners[j][1];
				// 	}
				// 	sticker.x = x;
				// 	sticker.y = y;
				// }
				upload_pic(data, JSON.stringify(stickers_send));
			}

			function upload_pic(pic, data)
			{
				const body = 	"action=upload&picture=" + encodeURIComponent(pic) + "&stickers=" + encodeURIComponent(data);
				fetch("./upload.php", {
					method: "post",
					credentials: "include",
					headers: {"Content-type": "application/x-www-form-urlencoded; charset=UTF-8"},
					body,
				})
				.then(response => {
					response.text().then(data => {
						console.log(data);
						// var response = JSON.parse(data);
						// if (response.error)
						// 	info(response.message, true);
						// else
						// {
						// 	info(response.message);
						// }
					});
				});
			}

			navigator.camera = (navigator.getUserMedia ||
								navigator.webkitGetUserMedia ||
								navigator.mozGetUserMedia ||
								navigator.msGetUserMedia);

			navigator.camera({ video: true, audio: false},
				function(stream)
				{
					video.src = window.URL.createObjectURL(stream);
					video.play();
				},
			err);

			function err(error)
			{
				console.log(error);
			}

			var drag = false;
			var img;
			var stickers = [];

			function changeSize(element)
			{
				var width = 400*(element.value/100);
				var maxWidth = document.getElementById("camera-container").clientWidth;
				if (width > maxWidth)
					width = maxWidth;
				var img_id = element.parentNode.id.replace("sticker_", "");
				element.parentNode.style.width = width + "px";
				stickers[img_id].width = width;
				stickers[img_id].height = element.parentNode.clientHeight;
				check_stickers();
			}

			function changeRotation(element)
			{
				var img_id = element.parentNode.id.replace("sticker_", "");
				document.getElementById("sticker_" + img_id + "_img").style.transform = "rotate(" + element.value + "deg)";
				stickers[img_id].rot = element.value;
				check_stickers();
			}

			function newSticker(src)
			{
				if (stickers.filter(Boolean).length < 5)
				{
					document.getElementById("stickers-canvas").innerHTML += "<div id='sticker_" + (stickers.length) + "' class='dragme'><img src='./img/stickers/" + src + "' class='sticker' id='sticker_" + stickers.length + "_img'><button class='sticker-del' onclick='delSticker(" + stickers.length + ")'>X</button><input type='range' min='40' max='100' value='50' class='slider' oninput='changeSize(this)'><br><input type='range' min='1' max='360' value='0' class='slider slider-vert' oninput='changeRotation(this)'></div>";
					stickers.push({x: 0, y: 0, height: document.getElementById("sticker_" + stickers.length).clientHeight, width: 200, rot: 0, src: src});
				}
				else
					info("You are using the maximum amount of stickers already.", true);

			}
			function delSticker(id)
			{
				document.getElementById("sticker_" + id).remove();
				delete stickers[id];
			}
			function startDrag(e) {
				// determine event object
				if (!e)
					var e = window.event;

				// IE uses srcElement, others use target
				img = e.target ? e.target : e.srcElement;

				if (img.className != 'dragme') {return};
				if(e.preventDefault) e.preventDefault();
				// calculate event X, Y coordinates
				offsetX = e.clientX;
				offsetY = e.clientY;

				// assign default values for top and left properties
				if(!img.style.marginLeft) { img.style.marginLeft='0px'};
				if (!img.style.marginTop) { img.style.marginTop='0px'};

				// calculate integer values for top and left 
				// properties
				coordX = parseInt(img.style.marginLeft);
				coordY = parseInt(img.style.marginTop);
				drag = true;

				document.onmousemove = dragElement;
				return false;
			}
			function dragElement(e) {
				if (!drag) {return};
				if (!e) { var e= window.event};

				var left = coordX+e.clientX-offsetX;
				var top = coordY+e.clientY-offsetY;
				var maxLeft = document.getElementById("camera-container").clientWidth - img.clientWidth;
				var maxTop = document.getElementById("camera-container").clientHeight - img.clientHeight;

				if (left <= 0) {left = 0};
				if (top <= 0) {top = 0};
				if (left >= maxLeft) {left = maxLeft};
				if (top >= maxTop) {top = maxTop};

				img.style.marginLeft = left + 'px';
				img.style.marginTop = top + 'px';
				var img_id = parseInt(img.id.replace("sticker_", ""));
				stickers[img_id].x = left;
				stickers[img_id].y = top;
				return false;
			}
			function stopDrag() {
				drag=false;
			}
			function check_stickers() {
				for (i in stickers) {
					var img = document.getElementById("sticker_" + i);
					var maxWidth = document.getElementById("camera-container").clientWidth;
					var maxHeight = document.getElementById("camera-container").clientHeight;

					if (stickers[i].x + stickers[i].width > maxWidth)
					{
						img.style.marginLeft = (maxWidth - stickers[i].width) + "px";
						stickers[i].x = maxWidth - stickers[i].width;
					}
					if (stickers[i].y + stickers[i].height > maxHeight)
					{
						img.style.marginTop = (maxHeight - stickers[i].height) + "px";
						stickers[i].y = maxHeight - stickers[i].height;
					}
					if (stickers[i].x < 0) {
						img.style.marginLeft = 0 + "px";
						stickers[i].x = 0;
					}
					if (stickers[i].y < 0) {
						img.style.marginTop = 0 + "px";
						stickers[i].y = 0;
					}
					if (stickers[i].width > maxWidth) {
						img.style.width = maxWidth + "px";
						stickers[i].width = maxWidth;
					}
					while (stickers[i].height > maxHeight) {
						img.style.width = (stickers[i].width - 10) + "px";
						stickers[i].width = (stickers[i].width - 10);
						stickers[i].height = img.clientHeight;
					}
				}
			}
			function getPixelsByAngle(x,y,halfWidth,halfHeight,angle){
				var bounds = [
					//upper left
					[x + (halfWidth) * Math.cos(angle) - (halfHeight) * Math.sin(angle) + halfWidth, y + (halfHeight) * Math.cos(angle) + (halfWidth) * Math.sin(angle) + halfHeight],
					//upper right
					[x - (halfWidth) * Math.cos(angle) - (halfHeight) * Math.sin(angle) + halfWidth, y + (halfHeight) * Math.cos(angle) - (halfWidth) * Math.sin(angle) + halfHeight],
					//bottom right
					[x - (halfWidth) * Math.cos(angle) + (halfHeight) * Math.sin(angle) + halfWidth, y - (halfHeight) * Math.cos(angle) - (halfWidth) * Math.sin(angle) + halfHeight],
					//bottom left
					[x + (halfWidth) * Math.cos(angle) + (halfHeight) * Math.sin(angle) + halfWidth, y - (halfHeight) * Math.cos(angle) + (halfWidth) * Math.sin(angle) + halfHeight]
				];
				return bounds;
			}
			window.onload = function() {
				document.onmousedown = startDrag;
				document.onmouseup = stopDrag;
				window.onresize = function(){check_stickers()};
			}
		</script>
		<?php
	}
?>