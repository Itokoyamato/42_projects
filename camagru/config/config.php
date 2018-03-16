<?php
	session_start();
	
	define("PATH_ROOT", $_SERVER['DOCUMENT_ROOT']."/camagru/");
	define("PATH_CONFIG", PATH_ROOT."config/");
	define("PATH_CSS", PATH_ROOT."css/");
	define("PATH_IMG", PATH_ROOT."img/");
	define("PATH_VIEW", PATH_ROOT."view/");
	define("PATH_FT", PATH_ROOT."functions/");

	define("PATH_ROOT_HTTP", "http://localhost:4242/camagru/");
	define("PATH_CONFIG_HTTP", PATH_ROOT_HTTP."config/");
	define("PATH_CSS_HTTP", PATH_ROOT_HTTP."css/");
	define("PATH_IMG_HTTP", PATH_ROOT_HTTP."img/");
	define("PATH_VIEW_HTTP", PATH_ROOT_HTTP."view/");
	define("PATH_FT_HTTP", PATH_ROOT_HTTP."functions/");

	date_default_timezone_set("Europe/Paris");

	include_once PATH_FT."account.php";

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
			echo $err->getMessage();
			exit();
		}
	}
	$account = new Account();
?>