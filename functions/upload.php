<?php
	include_once "account.php";
	if (isset($_POST['action']) && $_POST['action'] != "" && isset($_POST['token']) && $_POST['token'] != "")
	{
		$user_id = $account->isLoggedIn($_POST['token']);
		if (isset($user_id['error']))
			exit(json_encode(response(false, "[U001] An error occured. Try again, if this issues persists, contact an Administrator.", "")));
		$user_id = $user_id['data'];
		if ($_POST['action'] == "upload" && isset($_POST['picture']) && $_POST['picture'] != "" && isset($_POST['stickers']) && $_POST['stickers'] != "" && isset($_POST['title']) && $_POST['title'] != "")
		{
			$data = base64_decode(preg_replace('#^data:image/\w+;base64,#i', '', $_POST['picture']));
			$picture = imagecreatefromstring($data);
			if (!$picture)
				exit(json_encode(response(false, "[U002] The image uploaded, or camera snapshot seem to be invalid. Try again, if this issues persists, contact an Administrator.", "")));

			$stickers = json_decode($_POST['stickers'], true);

			foreach ($stickers as $key => $sticker) {
				$img = imagecreatefrompng("./img/stickers/".$sticker['src']);
				if (!$img)
					exit(json_encode(response(false, "[U003] Failed to process the stickers. Try again, if this issues persists, contact an Administrator.", "")));
				$img = resizePng($img, $sticker['width'], $sticker['height']);

				$w_original = imagesx($img);
				$h_original = imagesy($img);

				$img = rotate_transparent_img($img, -$sticker['rot']);

				$width = imagesx($img);
				$height = imagesy($img);

				$offset_x = $w_original - $width;
				$offset_y = $h_original - $height;

				imagecopyresampled($picture, $img, $sticker['x'] + $offset_x/2, $sticker['y'] + $offset_y/2, 0, 0, $width, $height, $width, $height);
				imagedestroy($img);
			}

			$newHeight = imagesy($picture) / (imagesx($picture)/720);
			$picture = resizePng($picture, 720, $newHeight);

			$day = date("d");
			$month = date("m");
			$year = date("Y");

			if (!file_exists("./img/uploads/".$year))
				mkdir("./img/uploads/".$year);
			if (!file_exists("./img/uploads/".$year."/".$month))
				mkdir("./img/uploads/".$year."/".$month);
			if (!file_exists("./img/uploads/".$year."/".$month."/".$day))
				mkdir("./img/uploads/".$year."/".$month."/".$day);

			$destFolder = "./img/uploads/".$year."/".$month."/".$day;

			try
			{
				// Retrieve user's id from his token
				$query = $account->getDB()->prepare("SELECT user_id FROM users_sessions WHERE token=:token");
				$query->execute(array(":token" => $_POST['token']));
				$row = $query->fetch(PDO::FETCH_ASSOC);
				if ($query->rowCount() == 0)
					exit(json_encode(response(false, "[U004] An error occured. Try again, if this issues persists, contact an Administrator.", "")));

				// Insert image in database
				$query = $account->getDB()->prepare("INSERT INTO images (user_id, title, date_created) VALUES (:user_id, :title, NOW())");
				$query->execute(array(":user_id" => $row['user_id'], ":title" => $_POST['title']));
				if ($query->rowCount() == 0)
					exit(json_encode(response(false, "[U005] An error occured. Try again, if this issues persists, contact an Administrator.", "")));

				// Create image and save file
				$destPath = $destFolder."/".$account->getDB()->lastInsertId().".png";
				imagepng($picture, $destPath);
				imagedestroy($picture);
				if (!is_file($destPath))
					exit(json_encode(response(false, "[U006] An error occured. Try again, if this issues persists, contact an Administrator.", "")));
				else
					exit(json_encode(response(true, "Successfully created your image !", "")));
			}
			catch(PDOException $ex)
			{
				exit(json_encode(response(false, $ex->getMessage(), "")));
			}
			exit(json_encode(response(false, "[U007] An error occured. Try again, if this issues persists, contact an Administrator.", "")));
		}
		elseif ($_POST['action'] == "delete" && isset($_POST['id']) && $_POST['id'] != "")
		{
			try
			{
				// Retrieve image data
				$query = $account->getDB()->prepare("SELECT * FROM images WHERE id=:id");
				$query->execute(array(":id" => $_POST['id']));
				$row = $query->fetch(PDO::FETCH_ASSOC);
				if ($query->rowCount() == 0)
					exit(json_encode(response(false, "[U008] An error occured. Try again, if this issues persists, contact an Administrator.", "")));

				// Check if it's the user's image
				if ($row['user_id'] != $user_id)
					exit(json_encode(response(false, "[U009] An error occured. Try again, if this issues persists, contact an Administrator.", "")));

				// Get path to image
				$date = strtotime($row['date_created']);
				$year = date("Y", $date);
				$month = date("m", $date);
				$day = date("d", $date);
				$path = "./img/uploads/".$year."/".$month."/".$day."/".$row['id'].".png";

				// Delete in DB
				$query = $account->getDB()->prepare("DELETE FROM images WHERE id=:id");
				$query->execute(array(":id" => $_POST['id']));
				if ($query->rowCount() == 0)
					exit(json_encode(response(false, "[U010] An error occured. Try again, if this issues persists, contact an Administrator.", "")));
			}
			catch(PDOException $ex)
			{
				exit(json_encode(response(false, $ex->getMessage(), "")));
			}

			// Delete image
			if (!unlink($path))
				exit(json_encode(response(false, "[U011] An error occured. Try again, if this issues persists, contact an Administrator.", "")));
			exit(json_encode(response(true, "Successfully deleted your image.", "")));
		}
		else
			exit(json_encode(response(false, "[U012] Invalid request.", "")));
	}
	else
		exit(json_encode(response(false, "[U013] Invalid request.", "")));

	// Functions
	function rotate_transparent_img($img_resource, $angle){
		$transparency = imagecolorallocatealpha($img_resource,0,0,0,127);
		$rotated = imagerotate($img_resource, $angle, $transparency, 1);
		imagealphablending($rotated, false);
		imagesavealpha($rotated, true);
		return ($rotated);
	}
	function resizePng($im, $dst_width, $dst_height) {
	    $width = imagesx($im);
	    $height = imagesy($im);
	    $newImg = imagecreatetruecolor($dst_width, $dst_height);
	    imagealphablending($newImg, false);
	    imagesavealpha($newImg, true);
	    $transparent = imagecolorallocatealpha($newImg, 255, 255, 255, 127);
	    imagefilledrectangle($newImg, 0, 0, $width, $height, $transparent);
	    imagecopyresampled($newImg, $im, 0, 0, 0, 0, $dst_width, $dst_height, $width, $height);
	    return $newImg;
	}
?>