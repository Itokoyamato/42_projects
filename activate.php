<?php
	if (isset($_GET['token']) && $_GET['token'] != "")
	{
		include_once "./header.php";
		$validate = $account->activateAccount($_GET['token']);
		print_r($validate);
	}
	else
		header("Location: ./");
?>
<meta http-equiv="refresh" content="5;URL='./'">