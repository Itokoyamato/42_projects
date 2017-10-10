<?php
	include_once "./account.php";
	if (isset($_POST['action']))
	{
		$action = $_POST['action'];
		if ($action == "register" && isset($_POST['username']) && isset($_POST['email']) && isset($_POST['password']))
		{
			$username = $_POST['username'];
			$email = $_POST['email'];
			$password = $_POST['password'];
			echo $account->register($username, $email, $password);
		}
		if ($action == "login" && isset($_POST['username']) && isset($_POST['password']))
		{
			$username = $_POST['username'];
			$password = $_POST['password'];
			echo $account->login($username, $password);
		}
	}
?>