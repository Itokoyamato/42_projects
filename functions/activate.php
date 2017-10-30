<?php
	include_once "../config/config.php";
	if (isset($_GET['token']) && $_GET['token'] != "")
	{
		include_once "./header.php";
		$validate = $account->activateAccount($_GET['token']);
		if (isset($validate['error'])): ?>
			<script>
				info('<?php echo $validate['message'] ?>', true);
			</script>
		<?php else: ?>
			<script>
				info('<?php echo $validate['message'] ?>');
				setTimeout(function(){window.location.href = "./";}, 2000);
			</script>
		<?php endif;
	}
	else
		header("Location: ./");
?>