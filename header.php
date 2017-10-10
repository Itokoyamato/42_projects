<?php
	include_once "auth.php";
?>
<html>
	<style>
		html, body {
			margin: 0;
			padding: 0;
			background: #E8EAF6;
		}
		header {
			width: 100%;
			height: 50px;
			background: #2957b5;
			border-bottom: solid 2px #283593;
			box-shadow: 0px 0px 10px #000
		}
		.logo {
			width: 20%;
			height: 100%;
			float: left;
			display: inline-block;
		}
		.title {
			color: #ffffff;
			font-family: 'Raleway', sans-serif;
			font-size: 30px;
			font-weight: 800;
			line-height: 50px;
			text-align: center;
			text-decoration: none;
			letter-spacing: 3px;
			height: 100%;
			width: 100%;
		}
		.account {
			float: right;
			height: 100%;
		}
		.drop {
			display: none;
			visibility: hidden;
			opacity: 0;
			transition-duration: 0.4s;
			width: 100%;
		}
		.account-drop {
			float: right;
			width: 150px;
		}
		.account-drop:hover .drop {
			float: right;
			display: block;
			visibility: visible;
			opacity: 1;
		}
		.drop-button {
			height: 50px;
			width: 80%;
			border: none;
			background: #eee;
			border-left: solid 4px #283593;
			border-right: solid 4px #283593;
			border-top: solid 1px #283593;
			transition-duration: 0.4s;
			float: right;
			right: 0;
			box-shadow: 0px 8px 16px 0px;
		}
		.drop-button:hover {
			background: #C5CAE9;
		}
		.drop-button-main {
			height: 100%;
			width: 100%;
			border-top: none;
			background: #E8EAF6;
			border-bottom-left-radius: 100px;
			box-shadow: inset 0 0 10px;
			border-right: solid 2px #283593;
		}
	</style>
	<header class="header">
		<div class="logo"><a class="title" href="./">Camagru</a></div>
		<div class="account">
			<?php if ($account->isLoggedIn()): ?>
			<div class="account-drop">
				<button class="drop-button drop-button-main">Account</button>
				<div class="drop">
					<button class="drop-button" onclick="location.href='./settings.php';">Settings</button>
					<br>
					<button class="drop-button" onclick="location.href='./logout.php';">Log out</button>
				</div>
			</div>
			<?php else: ?>
			<div class="account-drop">
				<button class="drop-button drop-button-main">Account</button>
				<div class="drop">
					<button class="drop-button" onclick="location.href='./login.php';">Sign in</button>
					<br>
					<button class="drop-button" onclick="location.href='./register.php';">Register</button>
				</div>
			</div>
			<?php endif; ?>
		</div>
	</header>
</html>