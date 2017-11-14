<?php
	include_once $_SERVER['DOCUMENT_ROOT']."/camagru/config/config.php";
	if (isset($_GET['token']) && $_GET['token'] != "")
	{
		include_once PATH_VIEW."header.php";
		$validate = $account->activateAccount($_GET['token']);
		if (isset($validate['error'])): ?>
			<script>
				info('<?php echo $validate['message'] ?>', true);
			</script>
		<?php else: ?>
			<script>
				info('<?php echo $validate['message'] ?>');
				setTimeout(function(){window.location.href = "<?php echo PATH_ROOT_HTTP ?>";}, 2000);
			</script>
		<?php endif;
		include_once PATH_VIEW."footer.php";
	}
	else
		header("Location: ".PATH_ROOT_HTTP);
?>