#!/usr/bin/php
<?php
	date_default_timezone_set('Europe/Paris');
	$utmp = fopen("/var/run/utmpx", "r");
	if (!$utmp)
		exit("Failed opening utmpx file\n");
	while ($utmpx = fread($utmp, 628))
	{
		$array = unpack("a256user/a4num/a32term/iD/iE/I2time", $utmpx);
		$data[$array['term']] = $array;
	}
	sort($data);
	foreach ($data as $val)
		if ($val['E'] == 7)
			echo $val['user'] . " ".$val['term'] . "  ".date("M j", $val['time1']) . " ".date("H:i", $val['time1']) . "\n";
?>