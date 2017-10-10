<?php
	include_once "./account.php";
	if ($account->isLoggedIn())
	{
		if ($account->logout())
		{
			include("./header.php");
			echo "You have been logged out.\nRedirecting you in 5 seconds.";
		}
	}
	else
		header("Location: ./");
?>
<meta http-equiv="refresh" content="5;URL='./'">