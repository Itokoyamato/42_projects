<?php
	include_once "header.php";
?>
<html>
	<form method="post" action="javascript:void(0);" onSubmit="return register()">
		<input type="text" name="username" id="register_username" placeholder="Username" />
		<input type="text" name="email" id="register_email" placeholder="Email" />
		<input type="password" name="pwd" id="register_pwd" placeholder="Password" />
		<input type="password" name="pwd2" id="register_pwd2" placeholder="Comfirm Password" />
		<input type="submit" value="Register"/>
	</form>
	<script>
		const register_username = document.getElementById("register_username");
		const register_email = document.getElementById("register_email");
		const register_password = document.getElementById("register_pwd");
		const register_password2 = document.getElementById("register_pwd2");

		function register()
		{
			const body = 	"action=register&username=" + encodeURIComponent(register_username.value) +
							"&email=" + encodeURIComponent(register_email.value) +
							"&password=" + encodeURIComponent(register_password.value);
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
				});
			});
		}
	</script>
</html>