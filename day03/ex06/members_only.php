<?php
	if (!isset($_SERVER['PHP_AUTH_USER'])) {
		header("WWW-Authenticate: Basic  Basic realm=''Espace membres''");
		header("HTTP/1.0 401 Unauthorized");
		echo '<html><body>Cette zone est accessible uniquement aux membres du site</body></html>';
	} else {
		if ($_SERVER['PHP_AUTH_USER'] == "zaz" && $_SERVER['PHP_AUTH_PW'] == "jaimelespetitsponeys")
			echo "<html><body>\nBonjour Zaz<br />\n<img src='data:image/png;base64,".base64_encode(file_get_contents("../img/42.png"))."'>\n</body></html>\n";
		else
		{
			header("WWW-Authenticate: Basic  Basic realm=''Espace membres''");
			header("HTTP/1.0 401 Unauthorized");
			echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n";
		}

	}
?>