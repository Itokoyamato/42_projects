<html>
	<form method="post" action="javascript:void(0);" onSubmit="return register()">
		<input type="text" name="login_username" id="login_username" placeholder="username" />
		<input type="password" name="login_password" id="login_password" placeholder="Password" />
		<p>Forgot password ? <a href="./forgot.php">Click here</a></p>
		<p>Don't have account yet ? <a href="./register.php">Register here</a></p>
		<input type="submit" value="Send"/>
	</form>
	<script>
		const login_username = document.getElementById("login_username");
		const login_password = document.getElementById("login_password");

		function register()
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
					switch (parseInt(data))
					{
						case 1:
							console.log("Logged in successfully");
							break;
						case 2:
							console.log("Invalid credentials");
							break;
						default:
							console.log("Error " + response.status);
					}
				});
			});
		}
	</script>
</html>