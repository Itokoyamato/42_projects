<?php
	include_once "./account.php";
	if (isset($_POST['action']))
	{
		$action = $_POST['action'];
		if ($action == "register")
		{
			if (isset($_POST['username']) && $_POST['username'] != "" && isset($_POST['email']) && $_POST['email'] != "" && isset($_POST['password']) && $_POST['password'] != "")
				echo json_encode($account->register($_POST['username'], $_POST['email'], $_POST['password']));
		}
		elseif ($action == "login")
		{
			if (isset($_POST['username']) && $_POST['username'] != "" && isset($_POST['password']) && $_POST['password'] != "")
				echo json_encode($account->login($_POST['username'], $_POST['password']));
		}
		elseif ($action == "reset")
		{
			if (isset($_POST['email']) && $_POST['email'] != "")
				echo json_encode($account->resetPass_send($_POST['email']));
			elseif (isset($_POST['token']) && $_POST['token'] != "" && isset($_POST['password']) && $_POST['password'] != "")
				echo json_encode($account->resetPass_set($_POST['token'], $_POST['password']));
		}
	}
?>