<?php
	include_once "header.php";
	try
	{
		// Retrieve user's id from his token
		// $query = $account->getDB()->prepare("SELECT user_id FROM users_sessions WHERE token=:token");
		// $query->execute(array(":token" => $_COOKIE['camagru_token']));
		// $row = $query->fetch(PDO::FETCH_ASSOC);
		// if ($query->rowCount() == 0)
		// 	exit(json_encode(response(true, "[I001] An error occured. Try again, if this issues persists, contact an Administrator.")));

		// Insert image in database
		$query = $account->getDB()->prepare("SELECT * FROM images");
		$query->execute();
		$rows = $query->fetchAll(PDO::FETCH_ASSOC);
		if ($query->rowCount() == 0)
			exit(json_encode(response(true, "[I001] An error occured. Try again, if this issues persists, contact an Administrator.")));
		foreach ($rows as $key => $image) {
			$date = strtotime($image['date_created']);
			$year = date("Y", $date);
			$month = date("m", $date);
			$day = date("d", $date);
			$path = "./img/uploads/".$year."/".$month."/".$day."/".$image['id'].".png";
			?>
			<div>
				<p><?php echo $image['title'] ?></p>
				<img src="<?php echo $path ?>">
			</div>
			<?php
		}
	}
	catch(PDOException $ex)
	{
		exit(json_encode(response(false, $ex->getMessage())));
	}
?>