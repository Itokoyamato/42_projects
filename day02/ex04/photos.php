#!/usr/bin/php
<?php
	function get_image_content($URL){
		$curl = curl_init();
		curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
		curl_setopt($curl, CURLOPT_URL, $URL);
		curl_setopt($curl, CURLOPT_BINARYTRANSFER, 1);
		curl_setopt($curl, CURLOPT_FOLLOWLOCATION, 1);
		$data = curl_exec($curl);
		curl_close($curl);
		return $data;
	}
	function get_content($URL){
		$curl = curl_init();
		curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
		curl_setopt($curl, CURLOPT_URL, $URL);
		curl_setopt($curl, CURLOPT_FOLLOWLOCATION, 1);
		$data = curl_exec($curl);
		curl_close($curl);
		return $data;
	}
	if (!$argv[1])
		exit (1);
	$page = get_content($argv[1]);
	preg_match_all('/<img.{0,}src=["|\/|h][[:graph:]]+/', $page, $imgs);
	$link = str_replace("http://", "", $argv[1]);
	$link = str_replace("https://", "", $link);
	if (count($imgs[0]) > 0 && !file_exists($link))
		mkdir($link);
	foreach ($imgs[0] as $i => $v) {
		$imgs[0][$i] = preg_replace('/"|>/', "", substr(strstr($imgs[0][$i], "src="), 5));
		$img_name = array_pop(explode('/', $imgs[0][$i]));
		if (preg_match("/^http/i", $imgs[0][$i]))
			file_put_contents($link."/".basename($img_name), get_image_content($imgs[0][$i]));
		else
			file_put_contents($link."/".basename($img_name), get_image_content($argv[1]."/".$imgs[0][$i]));
	}
?>