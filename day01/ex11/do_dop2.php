#!/usr/bin/php
<?php
	if ($argc != 2)
		exit ("Incorrect Parameters\n");
	elseif ($argc == 2)
	{
		$arr =  preg_split("/(\+|-|%|\/|\*)/", $argv[1], -1, PREG_SPLIT_DELIM_CAPTURE);
		$num1 = preg_replace("/\s+/", "", $arr[0]);
		$op = preg_replace("/\s+/", "", $arr[1]);
		$num2 = preg_replace("/\s+/", "", $arr[2]);
		if (!is_numeric($num1) || !is_numeric($num2))
			exit ("Syntax Error\n");
		if ($op == "+")
			echo $num1 + $num2."\n";
		elseif ($op == "-")
			echo $num1 - $num2."\n";
		elseif ($op == "*")
			echo $num1 * $num2."\n";
		elseif ($op == "/")
			echo $num1 / $num2."\n";
		elseif ($op == "%")
			echo $num1 % $num2."\n";
	}
?>