<?php
	session_start();
	$DB_NAME = "camagru";
	$DB_HOST = "localhost";
	$DB_DSN = "mysql:dbname={$DB_NAME};host={$DB_HOST};charset=utf8";
	$DB_USER = "root";
	$DB_PASSWORD = "password";

	function init_db()
	{
		global $DB_DSN;
		global $DB_USER;
		global $DB_PASSWORD;
		try {
			$db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
			$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			return($db);
		}
		catch(PDOException $err) {
			echo $err;
			exit();
		}
	}
	$account = new Account();
?>