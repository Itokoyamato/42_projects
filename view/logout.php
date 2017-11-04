<?php
	include_once $_SERVER['DOCUMENT_ROOT']."/camagru/config/config.php";
	include_once PATH_FT."account.php";
	if (!isset($account->isLoggedIn()['error']))
	{
		$logout = $account->logout();
		include_once PATH_VIEW."header.php";
		if (isset($logout['error'])): ?>
			<script>
				info('<?php echo $logout['message'] ?>', true);
			</script>
		<?php else: ?>
			<script>
				info('<?php echo $logout['message'] ?>');
				setTimeout(function(){window.location.href = "<?php echo PATH_ROOT_HTTP ?>";}, 2000);
			</script>
		<?php endif;
	}
	else
		header("Location: ".PATH_ROOT_HTTP);
?>