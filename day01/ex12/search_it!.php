#!/usr/bin/php
<?php
	foreach ($argv as $i => $value) {
		if ($i > 1)
			$array = explode(':', $value);
			if ($array[0] == $argv[1])
				$result = $array[1];
	}
	if ($result)
		echo $array[1]."\n";
?>