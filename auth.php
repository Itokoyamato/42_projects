<?php
	include('./account.php');
	if (isset($_POST['action']))
	{
		$action = $_POST['action'];
		if ($action == "register" && isset($_POST['username']) && isset($_POST['email']) && isset($_POST['password']))
		{
			$username = $_POST['username'];
			$email = $_POST['email'];
			$password = $_POST['password'];
			$account = new Account(array("username" => $username, "email" => $email, "password" => $password));
			echo $account->register();
		}
		if ($action == "login" && isset($_POST['username']) && isset($_POST['password']))
		{
			$username = $_POST['username'];
			$password = $_POST['password'];
			$account = new Account(array("username" => $username, "password" => $password));
			echo $account->login();
		}
	}
?>