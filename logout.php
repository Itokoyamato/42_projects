<?php
	include_once "./account.php";
	if (!$account->isLoggedIn()['error'])
	{
		$logout = $account->logout();
		include("./header.php");
		if ($logout['error']): ?>
			<script>
				info('<?php echo $logout['message'] ?>', true);
			</script>
		<?php else: ?>
			<script>
				info('<?php echo $logout['message'] ?>');
				setTimeout(function(){window.location.href = "./";}, 2000);
			</script>
		<?php endif;
	}
	else
		header("Location: ./");
?>