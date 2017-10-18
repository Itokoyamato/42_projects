<?php
	include_once "account.php";
	// if (isset($_POST['action']))
	// {
		// if (isset($_POST['picture']) && $_POST['picture'] != "" && isset($_POST['stickers']) && $_POST['stickers'] != "")
		// {
		// echo $_POST['picture'];
		// $data = base64_decode(preg_replace('#^data:image/\w+;base64,#i', '', $data));
			$data = base64_decode(preg_replace('#^data:image/\w+;base64,#i', '', $_POST['picture']));
			$img = imagecreatefromstring($data);
			$stickers = json_decode($_POST['stickers'], true);

			foreach ($stickers as $key => $sticker) {
				$img2 = imagecreatefrompng("./img/stickers/".$sticker['src']);
				$img2 = resizePng($img2, $sticker['width'], $sticker['height']);
				$width = imagesx($img2);
				$height = imagesy($img2);
				$img2 = rotate_transparent_img($img2, -$sticker['rot']);
				$width2 = imagesx($img2);
				$height2 = imagesy($img2);
				$offset_x = $width - $width2;
				$offset_y = $height - $height2;
				imagecopyresampled($img, $img2, $sticker['x'] + $offset_x/2, $sticker['y'] + $offset_y/2, 0, 0, $width2, $height2, $width2, $height2);
			}
			imagepng($img, "./bruhhhhhhhhhh.png");
			echo json_encode(response("hi", true));
		// }
	// }

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