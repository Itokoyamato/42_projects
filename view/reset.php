<?php 
	include_once $_SERVER['DOCUMENT_ROOT']."/camagru/config/config.php";
	if (isset($_GET['token']) && $_GET['token'] != ""):
		include_once PATH_VIEW."header.php";
		$reset = $account->resetPass_check($_GET['token']);
		if (isset($reset['error'])): ?>
			<script>
				info('<?php echo $reset['message'] ?>', true);
			</script>
		<?php else: ?>
			<html>
				<div class="container roll-in" id="reset-container">
					<div class="container title">Reset</div>
					<form method="post" action="javascript:void(0);" onSubmit="return change_password()">
						<input required type="password" id="reset_pwd" name="Password" placeholder="Password"
							oninput="form.reset_pwd2.pattern = escapeRegExp(this.value)"
							pattern="(?=^.{8,}$)(?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?!.*\s).*$" title="Password must:&#10;- be at least 7 characters long&#10;- Contain one uppercase letter&#10;- Contain one lowercase letter&#10;- Contain one number"/>

						<input required type="password" id="reset_pwd2" name="Password" placeholder="Comfirm Password" pattern="" title="Fields must match" />
						
						<input type="submit" value="Change password"/>
					</form>
				</div>
				<script>
					const reset_pwd = document.getElementById("reset_pwd");

					function change_password()
					{
						const body = 	"action=reset&token=<?php echo $_GET['token']; ?>&password=" + encodeURIComponent(reset_pwd.value);
						fetch("<?php echo PATH_FT_HTTP.'auth.php' ?>", {
							method: "post",
							credentials: "include",
							headers: {
									"Content-type": "application/x-www-form-urlencoded; charset=UTF-8"
							},
							body,
						})
						.then(response => {
							response.text().then(data => {
								// console.log(data);
								var response = JSON.parse(data);
								if (response.error)
									info(response.message, true);
								else
								{
									info(response.message);
									setTimeout(function(){window.location.href = "<?php echo PATH_ROOT_HTTP ?>";}, 2000);
								}
							});
						});
					}
				</script>
			</html>
		<?php endif;
		include_once PATH_VIEW."footer.php";
	else:
		header("Location: ".PATH_ROOT_HTTP);
	endif;
?>