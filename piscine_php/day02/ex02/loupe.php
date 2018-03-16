#!/usr/bin/php
<?php
	function toupper($arr)
	{
		return ($arr[1] . strtoupper($arr[2]) . $arr[3]);
	}

	function zoomlinks($arr)
	{
		$arr[0] = preg_replace_callback("/( title=\")(.*?)(\")/mi", 'toupper', $arr[0]);
		$arr[0] = preg_replace_callback("/(>)(.*?)(<)/si", 'toupper', $arr[0]);
		return $arr[0];	
	}
	
	if (!$argv[1] || !file_exists($argv[1]))
		exit();
	$page = file_get_contents($argv[1]);
	echo preg_replace_callback("/(<a )(.*?)(>)(.*?)(<\/a>)/si", 'zoomlinks', $page);
?>