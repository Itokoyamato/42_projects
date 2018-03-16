<?php
	session_start();
	if (isset($_GET['submit']) && $_GET['submit'] == "OK")
	{
		$_SESSION['login'] = $_GET['login'];
		$_SESSION['passwd'] = $_GET['passwd'];
	}
	if (isset($_SESSION['login']))
		$login = $_SESSION['login'];
	else
		$login = "";
	if (isset($_SESSION['passwd']))
		$passwd = $_SESSION['passwd'];
	else
		$passwd = "";
?>
<html><body>
<form action="." method="GET">
	Identifiant: <input type="text" name="login" value="<?php echo $login; ?>" />
	<br />
	Mot de passe: <input type="text" name="passwd" value="<?php echo $passwd; ?>" />
	<input type="submit" name="submit" value="OK" />
</form>
</body></html>
