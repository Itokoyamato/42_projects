#!/usr/bin/php
<?php
	function between($arg, $min, $max)
	{
		if (strlen($arg) >= $min && strlen($arg) <= $max)
			return (1);
		return (0);
	}

	if ($argv[1])
	{
		$days = array("lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche");
		$months = array("none", "janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre");
		$arr = explode(" ", strtolower($argv[1]));
		if (count($arr) != 5)
			exit ("Wrong Format\n");
		if (!array_search($arr[0], $days))
			exit ("Wrong Format\n");
		$day = $arr[1];
		$day_name = explode(" ", $argv[1])[0];
		if(preg_match('/[A-Z]/', $day_name) && !(strtoupper($day_name[0]) == $day_name[0]))
			exit ("Wrong Format\n");
		if (preg_match_all('/[A-Z]/', $day_name) > 1)
			exit ("Wrong Format\n");
		if (!between($day, 1, 2))
			exit ("Wrong Format\n");
		$month = array_search($arr[2], $months);
		$month_name = explode(" ", $argv[1])[2];
		if (preg_match('/[A-Z]/', $month_name) && !(strtoupper($month_name[0]) == $month_name[0]))
			exit ("Wrong Format\n");
		if (preg_match_all('/[A-Z]/', $month_name) > 1)
			exit ("Wrong Format\n");
		if (!$month || $month == 0)
			exit ("Wrong Format\n");
		$year = $arr[3];
		if (!$year)
			exit ("Wrong Format\n");
		$time = explode(":", $arr[4]);
		if (count($time) != 3)
			exit ("Wrong Format\n");
		if (!between($time[0], 1, 2) || !between($time[1], 1, 2) || !between($time[2], 1, 2))
			exit ("Wrong Format\n");
		date_default_timezone_set("Europe/Paris");
		$result = mktime(intval($time[0]), intval($time[1]), intval($time[2]), $month, $day, $year);
		echo "$result\n";
	}
?>