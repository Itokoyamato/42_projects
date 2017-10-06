<?php
session_start();

function init_db()
{
	$host = "localhost";
	$name = "camagru";
	$user = "root";
	$pass = "password";
	try {
		$db = new PDO("mysql:dbname={$name};host={$host};charset=utf8", $user, $pass);
		$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		return($db);
	}
	catch(PDOException $err) {
		echo $err->getMessage();
		exit();
	}
}

$account = new Account();
?>
