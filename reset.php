<?php 
	include_once "header.php";
	if (isset($_GET['token']) && $_GET['token'] != ""): ?>
		<html>
			<form method="post" action="javascript:void(0);" onSubmit="return change_password()">
				<input type="password" name="password" id="password" placeholder="password" />
				<input type="password" name="password2" id="password2" placeholder="password" />
				<input type="submit" value="Change password"/>
			</form>
			<script>
				const password = document.getElementById("password");
				const password2 = document.getElementById("password2");

				function change_password()
				{
					const body = 	"action=reset&token=<?php echo $_GET['token']; ?>&password=" + encodeURIComponent(password.value);
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
	<?php else: ?>
		<html>
			<form method="post" action="javascript:void(0);" onSubmit="return reset_password()">
				<input type="text" name="reset_email" id="reset_email" placeholder="email" />
				<input type="submit" value="Reset my password"/>
			</form>
			<script>
				const reset_email = document.getElementById("reset_email");

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
							
						});
					});
				}
			</script>
		</html>
	<?php endif;
?>