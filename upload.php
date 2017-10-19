<?php
	include_once "account.php";
	if (isset($_POST['action']))
	{
		if (isset($_POST['token']) && $_POST['token'] != "" && isset($_POST['picture']) && $_POST['picture'] != "" && isset($_POST['stickers']) && $_POST['stickers'] != "" && isset($_POST['title']) && $_POST['title'] != "")
		{
			$data = base64_decode(preg_replace('#^data:image/\w+;base64,#i', '', $_POST['picture']));
			$picture = imagecreatefromstring($data);
			if (!$picture)
				exit(json_encode(response(false, "[U001] The image uploaded, or camera snapshot seem to be invalid. Try again, if this issues persists, contact an Administrator.")));

			$stickers = json_decode($_POST['stickers'], true);

			foreach ($stickers as $key => $sticker) {
				$img = imagecreatefrompng("./img/stickers/".$sticker['src']);
				if (!$img)
					exit(json_encode(response(false, "[U002] Failed to process the stickers. Try again, if this issues persists, contact an Administrator.")));
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

			$newHeight = imagesy($picture) / (imagesx($picture)/480);
			$picture = resizePng($picture, 480, $newHeight);

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
					exit(json_encode(response(true, "[U003] An error occured. Try again, if this issues persists, contact an Administrator.")));

				// Insert image in database
				$query = $account->getDB()->prepare("INSERT INTO images (user_id, title, date_created) VALUES (:user_id, :title, NOW())");
				$query->execute(array(":user_id" => $row['user_id'], ":title" => $_POST['title']));
				if ($query->rowCount() == 0)
					exit(json_encode(response(true, "[U004] An error occured. Try again, if this issues persists, contact an Administrator.")));

				// Create image and save file
				$destPath = $destFolder."/".$account->getDB()->lastInsertId().".png";
				imagepng($picture, $destPath);
				imagedestroy($picture);
				if (!is_file($destPath))
					exit(json_encode(response(true, "[U005] An error occured. Try again, if this issues persists, contact an Administrator.")));
				else
					exit(json_encode(response(true, "Successfully created your image !")));
			}
			catch(PDOException $ex)
			{
				exit(json_encode(response(false, $ex->getMessage())));
			}
			exit(json_encode(response(false, "[U006] An error occured. Try again, if this issues persists, contact an Administrator.")));
		}
		else
			exit(json_encode(response(false, "[U007] Invalid request.")));
	}
	else
		exit(json_encode(response(false, "[U008] Invalid request.")));

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