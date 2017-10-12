<?php 
	include_once "header.php";
?>
<html>
	<form method="post" action="javascript:void(0);" onSubmit="return login()">
		<input type="text" name="login_username" id="login_username" placeholder="username" />
		<input type="password" name="login_password" id="login_password" placeholder="Password" />
		<p>Forgot password ? <a href="./reset.php">Click here</a></p>
		<p>Don't have account yet ? <a href="./register.php">Register</a></p>
		<input type="submit" value="Login"/>
	</form>
	<script>
		const login_username = document.getElementById("login_username");
		const login_password = document.getElementById("login_password");

		function login()
		{
			const body = 	"action=login&username=" + encodeURIComponent(login_username.value) +
							"&password=" + encodeURIComponent(login_password.value);
			fetch("./auth.php", {
				method: "post",
				credentials: "include",
				headers: {
						"Content-type": "application/x-www-form-urlencoded; charset=UTF-8"
				},
				body,
			})
			.then(response => {
				response.text().then(data => {
					console.log(data);
					var response = JSON.parse(data);
					if (response.error)
						info(response.message, true);
					else
					{
						info(response.message);
						setTimeout(function(){window.location.href = "./";}, 2000);
					}
				});
			});
		}
	</script>
</html>