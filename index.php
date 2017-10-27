<?php
	include_once "header.php";
	include_once "count.php";
	try
	{
		?><div class="gallery"><?php
		$query = $account->getDB()->prepare("SELECT * FROM images ORDER BY id DESC");
		$query->execute();
		$rows = $query->fetchAll(PDO::FETCH_ASSOC);
		foreach ($rows as $key => $image) {
			$query = $account->getDB()->prepare("SELECT * FROM users WHERE id=:user_id");
			$query->execute(array(":user_id" => $image['user_id']));
			$row = $query->fetch(PDO::FETCH_ASSOC);
			$date = strtotime($image['date_created']);
			$year = date("Y", $date);
			$month = date("m", $date);
			$day = date("d", $date);
			$path = "./img/uploads/".$year."/".$month."/".$day."/".$image['id'].".png";
			if (!file_exists($path))
				continue;
			?>
			<div id="<?php echo $image['id'] ?>" class="picture-holder">
				<div class="picture-content">
					<img class="picture" src="<?php echo $path ?>"/>
					<?php $like = ($user_id && didUserLike($image['id'], $user_id)['data']) ? "<font color='red'>♥</font> ".count_likes($image['id'])['data'] : "♥ ".count_likes($image['id'])['data'] ?>
						<button id="<?php echo 'like_'.$image['id'] ?>" class="like" onclick="like(<?php echo $image['id'] ?>)"><?php echo $like ?></button>
					<!-- <button class="comment">💬</button> -->
					<p class="title">"<?php echo htmlspecialchars($image['title']) ?>"</p><i>by <p class="username"><?php echo $row['username'] ?></p></i>
				</div>
			</div>
			<?php
		}
		?></div><?php
	}
	catch(PDOException $ex)
	{
		exit(json_encode(response(false, $ex->getMessage())));
	}
	?>
	<script>
		function like(id) {
			const body = "action=like&token=" + encodeURIComponent("<?php echo $_COOKIE['camagru_token'] ?>") + "&id=" + encodeURIComponent(id);
			console.log(body);
			fetch("./image.php", {
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