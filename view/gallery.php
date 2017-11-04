<?php
	include_once $_SERVER['DOCUMENT_ROOT']."/camagru/config/config.php";
	include_once PATH_FT."count.php";
	include_once PATH_VIEW."header.php";
	try
	{
		$query = $account->getDB()->prepare("SELECT COUNT(*) AS count FROM images");
		$query->execute();
		$total_items = $query->fetch(PDO::FETCH_ASSOC)['count'];
		$per_page = 10;
		$total_pages = ceil($total_items / $per_page);
		$current_page = 1;
		if (isset($_GET['p']) && $_GET['p'] != "" && is_numeric($_GET['p']))
		{
			if ($_GET['p'] < 1)
				$current_page = 1;
			elseif ($_GET['p'] >= $total_pages)
				$current_page = $total_pages;
			else
				$current_page = $_GET['p'];
		}
		$offset = ($current_page - 1) * $per_page;
		$query = $account->getDB()->prepare("SELECT * FROM images ORDER BY id DESC LIMIT :offset,:per_page");
		$query->bindParam(":offset", $offset, PDO::PARAM_INT);
		$query->bindParam(":per_page", $per_page, PDO::PARAM_INT);
		$query->execute();
		$rows = $query->fetchAll(PDO::FETCH_ASSOC);
	}
	catch(PDOException $ex)
	{
		info($ex->getMessage(), true);
	}
	?><div class="gallery"><?php
		try
		{
			foreach ($rows as $key => $image) {
				$query = $account->getDB()->prepare("SELECT * FROM users WHERE id=:user_id");
				$query->execute(array(":user_id" => $image['user_id']));
				$row = $query->fetch(PDO::FETCH_ASSOC);
				$date = strtotime($image['date_created']);
				$year = date("Y", $date);
				$month = date("m", $date);
				$day = date("d", $date);
				$path = PATH_IMG_HTTP."uploads/".$year."/".$month."/".$day."/".$image['id'].".png";
				$like = ($user_id && didUserLike($image['id'], $user_id)['data']) ? "<font color='red'>♥</font> ".count_likes($image['id'])['data'] : "♥ ".count_likes($image['id'])['data'];
				if (!@file_get_contents($path))
					continue;
				?>
				<div id="<?php echo $image['id'] ?>" class="picture-holder">
					<div class="picture-content">
						<div style="position: relative;">
							<img class="picture" src="<?php echo $path ?>"/>
							<button id="<?php echo 'like_'.$image['id'] ?>" class="like" onclick="like(<?php echo $image['id'] ?>)"><?php echo $like ?></button>
							<button class="comment" onclick="toggle_comments(true, <?php echo $image['id'] ?>)">💬 <?php echo count_comments($image['id'])['data'] ?></button>
						</div>
						<p class="title">"<?php echo htmlspecialchars($image['title']) ?>"</p><i>by <p class="username"><?php echo $row['username'] ?></p></i>
					</div>
				</div>
				<?php
			}
		}
		catch(PDOException $ex)
		{
			info($ex->getMessage(), true);
		}
		?>
		<div id="comments-outer" class="comments-outer">
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
			<button class="exit" onclick="toggle_comments(false)">X</button>
		</div>
		<br>
		<div class="container pagination">
			<?php 
			if ($current_page > 1) { ?>
				<a href="./?p=<?php echo ($current_page - 1) ?>">&laquo;</a>
			<?php }

			$start_pages = ($current_page - 3);
			if ($start_pages < 1)
				$start_pages = 1;

			$end_pages = ($current_page + 3);
			if ($end_pages >= $total_pages)
				$end_pages = $total_pages + 1;

			for ($i=$start_pages; $i < $end_pages; $i++) { 
				if ($i == $current_page){ ?>
					<a class="active" href="#"><?php echo $i ?></a>
				<?php } else { ?>
					<a href="./?p=<?php echo $i ?>"><?php echo $i ?></a>
				<?php }
			}

			if ($current_page+1 <= $total_pages){ ?>
				<a href="./?p=<?php echo ($current_page + 1) ?>">&raquo;</a>
			<?php }
		?>
		</div>

	</div>
	<script>
		document.getElementById("comments-outer").addEventListener("click",
			function(e) {
				if (e.target === this)
					toggle_comments(false);
			}
		);
		var pictures = document.getElementsByClassName("picture");
		for (var i = 0; i < pictures.length; i++)
		{
			pictures[i].parentElement.parentElement.style.width = pictures[i].clientWidth - 1;
		}
		var current_img_id;
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
					console.log(data);
					var response = JSON.parse(data);
					if (response.error)
						info(response.message, true);
					else
					{
						console.log(response.data);
						toggle_comments(true, current_img_id);
					}
				});
			});
		}
		function toggle_comments(toggle, id) {
			var element = document.getElementById("comments-outer");
			element.style.display = (toggle) ? "block" : "none";
			document.getElementById("comments-container").style.display = "none";
			document.getElementById("comments-container-loading").style.display = "inline-block";
			if (toggle)
			{
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
						console.log(data);
						var response = JSON.parse(data);
						if (response.error)
							info(response.message, true);
						else
						{
							console.log(response.data);
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
			} else {
				current_img_id = null;
			}
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
					console.log(data);
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