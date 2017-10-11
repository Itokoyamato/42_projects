<?php
	include("./account.php");
	if (isset($_GET['token']) && $_GET['token'] != "")
	{
		$validate = $account->activateAccount($_GET['token']);
		print_r($validate);
	}
?>