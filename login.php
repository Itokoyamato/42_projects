<?php 
	include_once "header.php";
?>
<html>
	<div class="container" id="login-container">
		<div class="container title">Login</div>
		<form method="post" action="javascript:void(0);" onSubmit="return login()">
			<input required type="text" name="login_username" id="login_username" placeholder="Username" />
			<input required type="password" name="login_password" id="login_password" placeholder="Password" />
			<input type="submit" value="Login"/>
		</form>
		<div class="container footer">
			<p>Forgot password ? <a href="#reset">Click here</a></p>
			<p>Don't have account yet ? <a href="#register" onclick="display('register')">Register</a></p>
		</div>
	</div>
	<div class="container" id="register-container">
		<div class="container title">Register</div>
		<form method="post" action="javascript:void(0);" onSubmit="return register()">
			<input required type="text" id="register_username" name="Username" placeholder="Username" pattern="[a-zA-Z0-9]{5,15}"
				title="Username must:&#10;- be at least 5 characters long&#10;- contain only alphanumeric characters.">

			<input required type="email" id="register_email" name="Email" placeholder="Email" pattern="[a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,4}$"
				title="Please enter a valid email address." />

			<input required type="password" id="register_pwd" name="Password" placeholder="Password" oninput="form.register_pwd2.pattern = escapeRegExp(this.value)"
				pattern="(?=^.{8,}$)(?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?!.*\s).*$" title="Password must:&#10;- be at least 7 characters long&#10;- Contain one uppercase letter&#10;- Contain one lowercase letter&#10;- Contain one number"/>

			<input required type="password" id="register_pwd2" name="Password" placeholder="Comfirm Password" pattern="" title="Fields must match" />

			<input type="submit" value="Register"/>
		</form>
		<div class="container footer">
			<p>Already have an account ? <a href="#login" onclick="display('login')">Login</a></p>
		</div>
	</div>
	<div class="container" id="reset-container">
		<div class="container title">Reset</div>
		<form method="post" action="javascript:void(0);" onSubmit="return reset_password()">
			<input required type="email" id="reset_email" name="Email" placeholder="Email" pattern="[a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,4}$"
				title="Please enter a valid email address." />
			<input type="submit" value="Reset my password"/>
		</form>
		<div class="container footer">
			<p>Go back to <a href="#login" onclick="display('login')">Login</a></p>
		</div>
	</div>
	<script>
		var hash = window.location.hash;
		if (hash != "")
			display(hash.slice(1));
		else
			display("login");
		window.onhashchange = function() {
			var hash = window.location.hash;
			if (hash != "")
				display(hash.slice(1));
		}
		const login_username = document.getElementById("login_username");
		const login_password = document.getElementById("login_password");

		const register_username = document.getElementById("register_username");
		const register_email = document.getElementById("register_email");
		const register_password = document.getElementById("register_pwd");
		const register_password2 = document.getElementById("register_pwd2");

		const reset_email = document.getElementById("reset_email");

		function display(element)
		{
			var div_register = document.getElementById("register-container");
			var div_login = document.getElementById("login-container");
			var div_reset = document.getElementById("reset-container");
			if (element == "register")
			{
				if (div_login.classList.contains("roll-in"))
				{
					div_login.classList.remove("roll-in");
					div_login.classList.add("roll-out");
				}
				if (div_reset.classList.contains("roll-in"))
				{
					div_reset.classList.remove("roll-in");
					div_reset.classList.add("roll-out");
				}
				setTimeout(function(){
					div_register.classList.add("roll-in");
					div_register.classList.remove("roll-out");
				}, 200);
			}
			else if (element == "login")
			{
				if (div_register.classList.contains("roll-in"))
				{
					div_register.classList.remove("roll-in");
					div_register.classList.add("roll-out");
				}
				if (div_reset.classList.contains("roll-in"))
				{
					div_reset.classList.remove("roll-in");
					div_reset.classList.add("roll-out");
				}
				setTimeout(function(){
					div_login.classList.remove("roll-out");
					div_login.classList.add("roll-in");
				}, 200);
			}
			else if (element == "reset")
			{
				if (div_register.classList.contains("roll-in"))
				{
					div_register.classList.remove("roll-in");
					div_register.classList.add("roll-out");
				}
				if (div_login.classList.contains("roll-in"))
				{
					div_login.classList.remove("roll-in");
					div_login.classList.add("roll-out");
				}
				setTimeout(function(){
					div_reset.classList.remove("roll-out");
					div_reset.classList.add("roll-in");
				}, 200);
			}
		}

		function login()
		{
			if (login_username.value == "" || login_password.value == "")
				return;
			const body = 	"action=login&username=" + encodeURIComponent(login_username.value) +
							"&password=" + encodeURIComponent(login_password.value);
			fetch("./auth.php", {
				method: "post",
				credentials: "include",
				headers: {"Content-type": "application/x-www-form-urlencoded; charset=UTF-8"},
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

		function reset_password()
		{
			const body = 	"action=reset&email=" + encodeURIComponent(reset_email.value);
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