#!/usr/bin/php
<?php
	function ft_split($str)
	{
		$result = explode(" ", $str);
		foreach ($result as $i => $current)
		{
			if (!strcmp("", $current))
				unset($result[$i]);
		}
		$result = array_values($result);
		sort($result);
		return ($result);
	}
?>