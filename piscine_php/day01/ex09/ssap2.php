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
	$default = explode(' ', $str);
	sort($default);
	foreach ($default as $i => $value)
		if (is_numeric($value))
			$num[] = $value;
		elseif (ctype_alpha($value))
			$alpha[] = $value;
		else
			$other[] = $value;
	if ($alpha)
	{
		sort($alpha, SORT_NATURAL | SORT_FLAG_CASE);
		echo implode("\n", $alpha)."\n";
	}
	if ($num)
	{
		sort($num, SORT_STRING);
		echo implode("\n", $num)."\n";
	}
	if ($other)
	{
		sort($other);
		echo implode("\n", $other)."\n";
	}
?>