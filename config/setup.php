<?php
	include_once $_SERVER['DOCUMENT_ROOT']."/camagru/config/database.php";
	if (file_exists('camagru.sql'))
	{
		try
		{
			$db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
			$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			$db->exec(file_get_contents("camagru.sql"));
			echo "Installed.";
		}
		catch(PDOException $ex)
		{
			exit($ex->getMessage());
		}
	}
?>