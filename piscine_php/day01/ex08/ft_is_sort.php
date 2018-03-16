#!/usr/bin/php
<?php
	function ft_is_sort($array)
	{
		$myArray = $array;
		sort($myArray);
		foreach ($array as $i => $value)
			if (strcmp($array[$i], $myArray[$i]))
				return (0);
		return (1);
	}
?>