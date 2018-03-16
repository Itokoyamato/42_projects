<?php
	if ($_POST['login'] != '' && $_POST['oldpw'] != '' && $_POST['newpw'] != '' && isset($_POST['submit']) && $_POST['submit'] == 'OK')
	{
		if (!file_exists("../private"))
			mkdir("../private");
		if (!file_exists("../private/passwd"))
		{
			$arr = array();
			file_put_contents("../private/passwd", serialize($arr));
		}
		$password = hash('whirlpool', $_POST['newpw']);
		$oldpw = hash('whirlpool', $_POST['oldpw']);
		$accounts = unserialize(file_get_contents("../private/passwd"));
		foreach ($accounts as $key => $account) {
			if ($account['login'] == $_POST['login'] && $account['passwd'] == $oldpw)
			{
				$exists = true;
				$accounts[$key]['passwd'] = $password;
				file_put_contents("../private/passwd", serialize($accounts));
				echo "OK\n";
				break;
			}
		}
		if (!$exists)
			echo "ERROR\n";
	}
	else
		echo "ERROR\n";
?>
