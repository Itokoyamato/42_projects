<?php
	include_once "./account.php";
	if (isset($account->isLoggedIn()['error']))
		header("Location: ./");
	else
	{
		include_once "./header.php";

		$query = $account->getDB()->prepare("SELECT user_id FROM users_sessions WHERE token=:token AND active=1");
		$query->execute(array(":token" => $_COOKIE['camagru_token']));
		$row = $query->fetch(PDO::FETCH_ASSOC);
		$rows = array();
		if ($query->rowCount() != 0)
		{
			$query = $account->getDB()->prepare("SELECT * FROM images WHERE user_id=:user_id ORDER BY id DESC");
			$query->execute(array(":user_id" => $row['user_id']));
			$rows = $query->fetchAll(PDO::FETCH_ASSOC);
		}
		?>
		<div class="container-outer">
			<div class="main-container">
				<div class="left">
					<div class="left-inner">
						<form method="post" action="javascript:void(0);" onSubmit="return takepicture()">
							<div class="container title-container">
								<input required type="text" id="picture-title" placeholder="You can add some text with the picture here" onkeydown="if (event.keyCode == 13) return (false);">
							</div>
							<div class="container camera-container" id="camera-container">
								<div class="stickers-canvas" id="stickers-canvas"></div>
								<video id="camera" class="camera" autoplay></video>
								<img id="picture" class="picture" src=""/>
							</div>
							<br>
							<div class="container options">
								<input type="button" class="button" onclick="use_camera()" value="Camera"/>
								<input type="submit" class="button"/>
								<input type="file" id="use-picture" onchange="use_picture(this)" style="display: none;"/>
								<input class="button" type="button" value="Picture" onclick="document.getElementById('use-picture').click();" />
							</div>
							<br>
							<div class="container stickers-container">
								<img class="sticker" src="./img/stickers/grumpy.png" onclick="javascript:newSticker('grumpy.png')">
								<img class="sticker" src="./img/stickers/nanachi.png" onclick="javascript:newSticker('nanachi.png')">
								<img class="sticker" src="./img/stickers/kebab.png" onclick="javascript:newSticker('kebab.png')">
							</div>
						</form>
					</div>
				</div>
				<div class="container right">
					<div class="container title">Your gallery</div>
					<?php
					foreach ($rows as $key => $image) {
						$date = strtotime($image['date_created']);
						$year = date("Y", $date);
						$month = date("m", $date);
						$day = date("d", $date);
						$path = "./img/uploads/".$year."/".$month."/".$day."/".$image['id'].".png";
						?>
						<div class="pic-holder">
							<p><?php echo $image['title'] ?></p>
							<img class="inner" src="<?php echo $path ?>">
						</div>
						<?php } ?>
				</div>
			</div>
		</div>
		<script>
			var mode = "none";
			var stickersEnabled = false;
			var video = document.querySelector("video");

			function use_camera() {
				navigator.camera = (navigator.getUserMedia ||
								navigator.webkitGetUserMedia ||
								navigator.mozGetUserMedia ||
								navigator.msGetUserMedia);
				navigator.camera({ video: true, audio: false},
					function(stream)
					{
						video.src = window.URL.createObjectURL(stream);
						video.play();
						mode = "camera";
						document.getElementById("picture").classList.remove("show");
						document.getElementById("camera").classList.add("show");
						document.getElementById("stickers-canvas").innerHTML = "";
						stickers = [];
						stickersEnabled = true;
					},
				function(err){
					info("Could not detect your camera. You can still use the picture mode, to upload your own snapshot.", true);
					mode = "picture";
				});
			}

			function use_picture(e) {
				var reader = new FileReader();
				reader.onload = function (event) {
					document.getElementById("picture").classList.add("show");
					document.getElementById("camera").classList.remove("show");
					document.getElementById('picture').src = event.target.result;
					mode = "picture";
					document.getElementById("stickers-canvas").innerHTML = "";
					stickers = [];
					stickersEnabled = true;
				}
				reader.readAsDataURL(e.files[0]);
			}

			function isPictureValid(blob, callback)
			{
				if (blob) {
					var URL = window.URL || window.webkitURL;
					var image = new Image();

					image.onload = function() {
						if (this.width) {
							URL.revokeObjectURL(image.src);
							image = null;
							callback(true);
						}
						else
						{
							URL.revokeObjectURL(image.src);
							image = null;
							callback(false);
						}
					};
					image.onerror = function() {
						URL.revokeObjectURL(image.src);
						image = null;
						callback(false);
					};
					image.src = URL.createObjectURL(blob);
				}
				else
					callback(false);
			}

			function takepicture() {
				if (stickers.filter(Boolean).length < 1)
				{
					info("You must add a sticker to upload the picture.", true);
					return;
				}
				var canvas = document.createElement("canvas");
				var context = canvas.getContext("2d");
				var width;
				var height;
				var image;
				if (mode == "camera")
				{
					width = video.clientWidth;
					height = video.clientHeight;
					image = video;
				}
				else if (mode == "picture")
				{
					width = document.getElementById("picture").clientWidth;
					height = document.getElementById("picture").clientHeight;
					image = document.getElementById("picture");
				}
				canvas.width = width;
				canvas.height = height;
				context.drawImage(image, 0, 0, width, height);

				var stickers_send = JSON.parse(JSON.stringify(stickers));
				var title = document.getElementById("picture-title").value;
				var picture = canvas.toBlob(function(blob){
					isPictureValid(blob, function(isValid){
						if (isValid)
						{
							var picture = canvas.toDataURL('image/png');
							upload_pic(picture, JSON.stringify(stickers_send), title);
						}
						else
							info("The image uploaded, or camera snapshot seem to be invalid. Try again, if this issues persists, contact an Administrator.");

					});
				}, 'image/png', 1.0);
			}

			function upload_pic(picture, stickers_data, title)
			{
				const body = 	"action=upload&token=" + encodeURIComponent("<?php echo $_COOKIE['camagru_token'] ?>") + "&picture=" + encodeURIComponent(picture) + "&stickers=" + encodeURIComponent(stickers_data) + "&title=" + encodeURIComponent(title);
				fetch("./upload.php", {
					method: "post",
					credentials: "include",
					headers: {"Content-type": "application/x-www-form-urlencoded; charset=UTF-8"},
					body,
				})
				.then(response => {
					response.text().then(data => {
						console.log(data);
						var response = JSON.parse(data);
						if (response.error)
							info(response.message, true);
						else
						{
							info(response.message);
						}
					});
				});
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
				if (!stickersEnabled)
				{
					info("You must enable your camera or upload a picture first.", true);
					return;
				}
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
			window.onload = function() {
				document.onmousedown = startDrag;
				document.onmouseup = stopDrag;
				window.onresize = function(){check_stickers()};
				use_camera();
			}
		</script>
		<?php
	}
?>