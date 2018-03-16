#!/usr/bin/php
<?php
	if (!$argv[1])
		exit (1);
	$array = preg_replace('#\s+#', ' ', $argv[1]);
	$array = explode(' ', $array);
	$fw = $array[0];
	unset($array[0]);
	array_push($array, $fw);
	echo implode(' ', $array)."\n";
?>