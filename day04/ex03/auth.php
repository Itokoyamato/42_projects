<?php
	function auth($login, $passwd)
	{
		if (!file_exists("../private/passwd"))
			return (false);
		$accounts = unserialize(file_get_contents("../private/passwd"));
		$password = hash('whirlpool', $passwd);
		foreach ($accounts as $key => $account)
			if ($account['login'] == $login && $account['passwd'] == $password)
				return (true);
		return (false);
	}
?>
