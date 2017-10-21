<?php
	include_once "header.php";
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
			<div class="picture-holder">
				<div class="picture-content">
					<img class="picture" src="<?php echo $path ?>"/>
					<p class="title">"<?php echo $image['title'] ?>"</p><i>by <p class="username"><?php echo $row['username'] ?></p></i>
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