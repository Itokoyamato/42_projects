<?php
	include_once "config/config.php";
	include_once PATH_FT."count.php";

	include_once PATH_VIEW."header.php";
	include_once PATH_VIEW."gallery.php";
	?>
	<script>
		function like(id) {
			const body = "action=like&token=" + encodeURIComponent("<?php echo $camagru_token ?>") + "&id=" + encodeURIComponent(id);
			console.log(body);
			fetch("<?php echo PATH_FT.'image.php' ?>", {
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
						// info(response.message);
						if (response.data[0])
							document.getElementById("like_" + id).innerHTML = "<font color='red'>♥</font> " + response.data[1];
						else
							document.getElementById("like_" + id).innerHTML = "♥ " + response.data[1];
					}
				});
			});
		}
	</script>
	<?php
?>