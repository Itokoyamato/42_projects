<?php
	include_once PATH_FT."count.php";
	try
	{
		$query = $account->getDB()->prepare("SELECT COUNT(*) AS count FROM images");
		$query->execute();
		$total_items = $query->fetch(PDO::FETCH_ASSOC)['count'];
		$per_page = 10;
		$total_pages = ceil($total_items / $per_page);
		$current_page = 1;
		if (isset($_GET['p']) && $_GET['p'] != "" && is_numeric($_GET['p']))
		{
			if ($_GET['p'] < 1)
				$current_page = 1;
			elseif ($_GET['p'] >= $total_pages)
				$current_page = $total_pages;
			else
				$current_page = $_GET['p'];
		}
		$offset = ($current_page - 1) * $per_page;
		$query = $account->getDB()->prepare("SELECT * FROM images ORDER BY id DESC LIMIT :offset,:per_page");
		$query->bindParam(":offset", $offset, PDO::PARAM_INT);
		$query->bindParam(":per_page", $per_page, PDO::PARAM_INT);
		$query->execute();
		$rows = $query->fetchAll(PDO::FETCH_ASSOC);
	}
	catch(PDOException $ex)
	{
		info($ex->getMessage(), true);
	}
	?><div class="gallery"><?php
		try
		{
			foreach ($rows as $key => $image) {
				$query = $account->getDB()->prepare("SELECT * FROM users WHERE id=:user_id");
				$query->execute(array(":user_id" => $image['user_id']));
				$row = $query->fetch(PDO::FETCH_ASSOC);
				$date = strtotime($image['date_created']);
				$year = date("Y", $date);
				$month = date("m", $date);
				$day = date("d", $date);
				$path = "./img/uploads/".$year."/".$month."/".$day."/".$image['id'].".png";
				if (!file_exists($path))
					continue;
				?>
				<div id="<?php echo $image['id'] ?>" class="picture-holder">
					<div class="picture-content">
						<img class="picture" src="<?php echo $path ?>"/>
						<?php $like = ($user_id && didUserLike($image['id'], $user_id)['data']) ? "<font color='red'>♥</font> ".count_likes($image['id'])['data'] : "♥ ".count_likes($image['id'])['data'] ?>
						<p class="title">"<?php echo htmlspecialchars($image['title']) ?>"</p><i>by <p class="username"><?php echo $row['username'] ?></p></i>
						<br>
						<button id="<?php echo 'like_'.$image['id'] ?>" class="like" onclick="like(<?php echo $image['id'] ?>)"><?php echo $like ?></button>
						<button class="comment">💬</button>
					</div>
				</div>
				<?php
			}
		}
		catch(PDOException $ex)
		{
			info($ex->getMessage(), true);
		}
		?><br>
		<div class="container pagination">
			<?php 
			if ($current_page > 1) { ?>
				<a href="./?p=<?php echo ($current_page - 1) ?>">&laquo;</a>
			<?php }

			$start_pages = ($current_page - 3);
			if ($start_pages < 1)
				$start_pages = 1;

			$end_pages = ($current_page + 3);
			if ($end_pages >= $total_pages)
				$end_pages = $total_pages + 1;

			for ($i=$start_pages; $i < $end_pages; $i++) { 
				if ($i == $current_page){ ?>
					<a class="active" href="#"><?php echo $i ?></a>
				<?php } else { ?>
					<a href="./?p=<?php echo $i ?>"><?php echo $i ?></a>
				<?php }
			}

			if ($current_page+1 <= $total_pages){ ?>
				<a href="./?p=<?php echo ($current_page + 1) ?>">&raquo;</a>
			<?php }
		?>
		</div>
	</div>
	<?php
?>