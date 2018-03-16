<?php
	include_once $_SERVER['DOCUMENT_ROOT']."/camagru/config/config.php";
	include_once PATH_FT."account.php";
	if (isset($_COOKIE['camagru_token']) && $_COOKIE['camagru_token'] != "")
	{
		$camagru_token = $_COOKIE['camagru_token'];
		$user_id = $account->isLoggedIn($_COOKIE['camagru_token']);
		if (isset($user_id['error']))
			$user_id = false;
		else
			$user_id = $user_id['data'];
	}
	else
	{
		$user_id = false;
		$camagru_token = "";
	}
?>
<html>
	<link rel="stylesheet" type="text/css" href="<?php echo PATH_CSS_HTTP.'camagru.css' ?>">
	<div class="header">
		<a class="title" href="<?php echo PATH_ROOT_HTTP ?>">Camagru</a>
		<div class="account">
			<?php if (!isset($account->isLoggedIn()['error'])): ?>
				<a href="<?php echo PATH_ROOT_HTTP ?>">Gallery</a> | <a href="<?php echo PATH_VIEW_HTTP.'montage.php' ?>">Take a picture !</a> | <a href="<?php echo PATH_VIEW_HTTP.'logout.php' ?>">Sign off</a>
			<?php else: ?>
				<a href="<?php echo PATH_ROOT_HTTP ?>">Gallery</a> | <a href="<?php echo PATH_VIEW_HTTP.'login.php#login' ?>">Sign in</a> | <a href="<?php echo PATH_VIEW_HTTP.'login.php#register' ?>">Register</a>
			<?php endif; ?>
		</div>
	</div>
	<div class="info" id="info">
		<div class="info-content" id="info-content"></div>
	</div>
	<script>
		var info_timeout;
		var info_timeout2;
		function info(msg, error)
		{
			document.getElementById("info").classList.remove("show");
			if (info_timeout)
				clearTimeout(info_timeout);
			info_timeout = setTimeout(function(){
				document.getElementById("info-content").innerHTML = msg;
				document.getElementById("info").classList.add("show");
				if (!error)
					document.getElementById("info").classList.remove("error");
				else
					document.getElementById("info").classList.add("error");
				if (info_timeout2)
					clearTimeout(info_timeout2);
				window.scrollTo(0, 0);
				info_timeout2 = setTimeout(function(){document.getElementById("info").classList.remove("show");}, 10000);
			}, 200);
		}
		function escapeRegExp(str) {
			return str.replace(/[\-\[\]\/\{\}\(\)\*\+\?\.\\\^\$\|]/g, "\\$&");
		}	
	</script>
</html>
