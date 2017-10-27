<?php
	include_once "auth.php";
	$user_id = $account->isLoggedIn($_POST['token']);
	if (isset($user_id['error']))
		$user_id = false;
	else
		$user_id = $user_id['data'];
?>
<html>
	<link rel="stylesheet" type="text/css" href="./css/camagru.css">
	<div class="header">
		<a class="title" href="./">Camagru</a>
		<div class="account">
			<?php if (!isset($account->isLoggedIn()['error'])): ?>
				<a href="./">Gallery</a> | <a href="./montage.php">Take a picture !</a> | <a href="./logout.php">Sign off</a>
			<?php else: ?>
				<a href="./">Gallery</a> | <a href="./login.php#login">Sign in</a> | <a href="./login.php#register">Register</a>
			<?php endif; ?>
		</div>
	</div>
	<div class="info" id="info">
		<div class="info-content" id="info-content"></div>
	</div>
	<script>
		var info_timeout;
		function info(msg, error)
		{
			document.getElementById("info-content").innerHTML = msg;
			document.getElementById("info").classList.add("show");
			if (!error)
				document.getElementById("info").classList.remove("error");
			else
				document.getElementById("info").classList.add("error");
			if (info_timeout)
				clearTimeout(info_timeout);
			info_timeout = setTimeout(function(){document.getElementById("info").classList.remove("show");}, 10000);
		}
		function escapeRegExp(str) {
			return str.replace(/[\-\[\]\/\{\}\(\)\*\+\?\.\\\^\$\|]/g, "\\$&");
		}	
	</script>
</html>
