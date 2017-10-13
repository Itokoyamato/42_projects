<?php
	include_once "auth.php";
?>
<html>
	<link rel="stylesheet" type="text/css" href="./css/camagru.css">
	<div class="header">
		<a class="title" href="./">Camagru</a>
		<div class="account">
			<?php if (!$account->isLoggedIn()['error']): ?>
				<a href="#">?</a> | <a href="./logout.php">Sign off</a>
			<?php else: ?>
				<a href="./login.php#login">Sign in</a> | <a href="./login.php#register">Register</a>
			<?php endif; ?>
		</div>
	</div>
	<div class="info" id="info">
		<div class="info-content" id="info-content"></div>
	</div>
	<script>
		function info(msg, error)
		{
			document.getElementById("info-content").innerHTML = msg;
			document.getElementById("info").classList.add("show");
			if (!error)
				document.getElementById("info").classList.remove("error");
			else
				document.getElementById("info").classList.add("error");
		}
		function escapeRegExp(str) {
			return str.replace(/[\-\[\]\/\{\}\(\)\*\+\?\.\\\^\$\|]/g, "\\$&");
		}	
	</script>
</html>
