<?php
	include_once "./account.php";
	if ($account->isLoggedIn()['error'])
		header("Location: ./");
	else
	{
		include_once "./header.php";
		?>
		<div class="main-container">
			<div class="container camera-container" id="camera-container">
				<div id="stickers-canvas">
					<div class="dragme"><img src="./img/stickers/grumpy.png"><button class="meh">X</button></div>
				</div>
				<video class="camera" autoplay></video>
				<!-- <canvas style="display:none;"></canvas> -->
			</div>
			<div class="container sidebar">
				<div class="container title">Your gallery</div>
			</div>
			<div class="container stickers-container">
				<img class="sticker" src="./img/stickers/grumpy.png" onclick="javascript:newSticker('grumpy.png')">
			</div>
		</div>
		<script>
			var video = document.querySelector("video");
			// var canvas = document.querySelector("canvas");
			// var ctx = canvas.getContext("2d");
			var localMediaStream = null;

			function snapshot() {
				if (localMediaStream) {
					ctx.drawImage(video, 0, 0);
					document.querySelector("img").src = canvas.toDataURL("image/webp");
				}
			}

			video.addEventListener('click', snapshot, false);

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
			var stickers = {};

			function newSticker(src)
			{
				console.log(src);
			}
			function startDrag(e) {
	            // determine event object
	            if (!e)
	                var e = window.event;
	            if(e.preventDefault) e.preventDefault();

	            // IE uses srcElement, others use target
	            img = e.target ? e.target : e.srcElement;

	            if (img.className != 'dragme') {return};
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
	            return false;
	        }
	        function stopDrag() {
	            drag=false;
	        }
	        window.onload = function() {
	            document.onmousedown = startDrag;
	            document.onmouseup = stopDrag;
	        }
		</script>
		<?php
	}
?>