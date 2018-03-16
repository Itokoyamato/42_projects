#!/usr/bin/php
<?php
	if (!$argv[1])
		exit (1);
	foreach ($argv as $i => $param)
	{
		if ($i > 0)
			if ($str)
				$str = "$str ".preg_replace('#\s+#', ' ', $param);
			else
				$str = preg_replace('#\s+#', ' ', $param);
	}
	$result = explode(' ', $str);
	sort($result);
	foreach ($result as $i => $word)
	{
		echo "$word\n";
	}
?>