#!/usr/bin/php
<?php
	if ($argc != 4)
		exit ("Incorrect Parameters\n");
	elseif ($argc == 4)
	{
		$num1 = preg_replace("/\s+/", "", $argv[1]);
		$op = preg_replace("/\s+/", "", $argv[2]);
		$num2 = preg_replace("/\s+/", "", $argv[3]);
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