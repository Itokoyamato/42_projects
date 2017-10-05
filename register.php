<?php
?>
<html>
	<form method="post" action="javascript:void(0);" onSubmit="return register()">
		<input type="text" name="username" id="username" placeholder="Username" />
		<input type="text" name="email" id="email" placeholder="Email" />
		<input type="password" name="pwd" id="pwd" placeholder="Password" />
		<input type="password" name="pwd2" id="pwd2" placeholder="Comfirm Password" />
		<input type="submit" value="Send"/>
	</form>
	<script>
		const username = document.getElementById("username");
		const email = document.getElementById("email");
		const password = document.getElementById("pwd");
		const password2 = document.getElementById("pwd2");

		function register()
		{
			const body = 	"action=register&username=" + encodeURIComponent(username.value) +
							"&email=" + encodeURIComponent(email.value) +
							"&password=" + encodeURIComponent(password.value);
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
					switch (parseInt(data))
					{
						case 1:
							console.log("Registered successfully");
							break;
						case 2:
							console.log("Username is already in use");
							break;
						case 3:
							console.log("Email is already in use");
							break;
						default:
							console.log("Error " + response.status);
					}
				});
			});
		}
	</script>
</html>