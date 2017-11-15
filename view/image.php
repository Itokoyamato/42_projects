<?php
	if (!isset($_GET['id']) || !is_numeric($_GET['id']) || $_GET['id'] == "")
		exit();
	include_once $_SERVER['DOCUMENT_ROOT']."/camagru/config/config.php";
	include_once PATH_FT."count.php";
	include_once PATH_VIEW."header.php";

	try
	{
		$query = $account->getDB()->prepare("SELECT * FROM images WHERE id=:img_id");
		$query->execute(array(":img_id" => $_GET['id']));
		$image = $query->fetch(PDO::FETCH_ASSOC);
	}
	catch(PDOException $ex)
	{
		info($ex->getMessage(), true);
	}
	?><div id="image-display" class="image-display"><?php
		try
		{
			$query = $account->getDB()->prepare("SELECT * FROM users WHERE id=:user_id");
			$query->execute(array(":user_id" => $image['user_id']));
			$row = $query->fetch(PDO::FETCH_ASSOC);
			$date = strtotime($image['date_created']);
			$year = date("Y", $date);
			$month = date("m", $date);
			$day = date("d", $date);
			$path = PATH_IMG_HTTP."uploads/".$year."/".$month."/".$day."/".$image['id'].".png";
			$like = ($user_id && didUserLike($image['id'], $user_id)['data']) ? "<font color='red'>♥</font> ".count_likes($image['id'])['data'] : "♥ ".count_likes($image['id'])['data'];
			?>
			<div id="<?php echo $image['id'] ?>" class="picture-holder">
				<div class="picture-content">
					<div style="position: relative;">
						<img class="picture" src="<?php echo $path ?>"/>
						<button id="<?php echo 'like_'.$image['id'] ?>" class="like" onclick="like(<?php echo $image['id'] ?>)"><?php echo $like ?></button>
						<button class="comment">💬 <?php echo count_comments($image['id'])['data'] ?></button>
					</div>
					<p class="title">"<?php echo htmlspecialchars($image['title']) ?>"</p><i>by <p class="username"><?php echo $row['username'] ?></p></i>
				</div>
			</div>
			<?php
		}
		catch(PDOException $ex)
		{
			info($ex->getMessage(), true);
		}
		?>
		<br>
		<div id="comments-container" class="container comments-container">
			<div id="comments" class="comments">
			</div>
			<div id="new-comment" class="new-comment">
				<form method="post" action="javascript:void(0);" onSubmit="return new_comment()">
					<input type="text" id="comment-text" placeholder="Write a comment ..."/>
					<input type="submit" value="comment"/>
				</form>
			</div>
		</div>
		<div id="comments-container-loading" class="container comments-container loading">
			<div id="loading" class="loading">
				<div class="spinner"></div>
			</div>
		</div>
	</div>
	<?php include_once PATH_VIEW."footer.php"; ?>
	<script>
		var current_img_id = <?php echo $_GET['id'] ?>;
		window.onload = function() {
			refresh_comments(current_img_id);
		}
		function new_comment() {
			var element = document.getElementById("comment-text");
			if (element.value == "" || !current_img_id)
				return ;
			const body = "action=newComment&id=" + encodeURIComponent(current_img_id) + "&comment=" + encodeURIComponent(element.value);
			fetch("<?php echo PATH_FT_HTTP.'comment.php' ?>", {
				method: "post",
				credentials: "include",
				headers: {"Content-type": "application/x-www-form-urlencoded; charset=UTF-8"},
				body,
			})
			.then(response => {
				response.text().then(data => {
					// console.log(data);
					var response = JSON.parse(data);
					if (response.error)
						info(response.message, true);
					else
					{
						// console.log(response.data);
						refresh_comments(current_img_id);
					}
				});
			});
		}
		function refresh_comments(id) {
			document.getElementById("comments-container").style.display = "none";
			document.getElementById("comments-container-loading").style.display = "inline-block";

			document.getElementById("comment-text").value = "";
			document.getElementById("comments").innerHTML = "";
			const body = "action=getComments&id=" + encodeURIComponent(id);
			fetch("<?php echo PATH_FT_HTTP.'comment.php' ?>", {
				method: "post",
				credentials: "include",
				headers: {"Content-type": "application/x-www-form-urlencoded; charset=UTF-8"},
				body,
			})
			.then(response => {
				response.text().then(data => {
					// console.log(data);
					var response = JSON.parse(data);
					if (response.error)
						info(response.message, true);
					else
					{
						// console.log(response.data);
						current_img_id = id;
						var html = "";
						for (i in response.data) {
							var comment = response.data[i];
							html += "<div class=comment>" +
										"<div class='username'>" + comment.username + ":</div><div class='date'>" + comment.date_added + "</div>" +
										"<div class='content'>" + comment.comment + "</div>" +
									"</div>";
						}
						document.getElementById("comments").innerHTML = html;
						document.getElementById("comments-container-loading").style.display = "none";
						document.getElementById("comments-container").style.display = "block";
					}
				});
			});
		}
		function like(id) {
			const body = "action=like&token=" + encodeURIComponent("<?php echo $camagru_token ?>") + "&id=" + encodeURIComponent(id);
			fetch("<?php echo PATH_FT_HTTP.'image.php' ?>", {
				method: "post",
				credentials: "include",
				headers: {"Content-type": "application/x-www-form-urlencoded; charset=UTF-8"},
				body,
			})
			.then(response => {
				response.text().then(data => {
					// console.log(data);
					var response = JSON.parse(data);
					if (response.error)
						info(response.message, true);
					else
					{
						// info(response.message);
						if (response.data[0])
							document.getElementById("like_" + id).innerHTML = "<font color='red'>♥</font> " + response.data[1];
						else
							document.getElementById("like_" + id).innerHTML = "♥ " + response.data[1];
					}
				});
			});
		}
	</script>
	<?php
?>