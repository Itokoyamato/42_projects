<?php
	if ($_POST['login'] != '' && $_POST['passwd'] != '' && isset($_POST['submit']) && $_POST['submit'] == 'OK')
	{
		if (!file_exists("../private"))
			mkdir("../private");
		if (!file_exists("../private/passwd"))
		{
			$arr = array();
			file_put_contents("../private/passwd", serialize($arr));
		}
		$accounts = unserialize(file_get_contents("../private/passwd"));
		foreach ($accounts as $key => $account) {
			if ($account['login'] == $_POST['login'])
			{
				$exists = true;
				break;
			}
		}
		if (!$exists)
		{
			$password = hash('whirlpool', $_POST['passwd']);
			$accounts[] = array("login"=>$_POST['login'], "passwd"=>$password);
			file_put_contents("../private/passwd", serialize($accounts));
			echo "OK\n";
		}
		else
			echo "ERROR\n";
	}
	else
		echo "ERROR\n";
?>
