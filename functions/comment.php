<?php
	include_once $_SERVER['DOCUMENT_ROOT']."/camagru/config/config.php";
	include_once PATH_FT."account.php";
	if (isset($_POST['action']) && $_POST['action'] != "")
	{
		if ($_POST['action'] == "getComments" && isset($_POST['id']) && $_POST['id'] != "" && is_numeric($_POST['id']))
		{
			try
			{
				$query = $account->getDB()->prepare("SELECT * FROM comments WHERE img_id=:img_id ORDER BY comments.date_added DESC");
				$query->execute(array(":img_id" => $_POST['id']));
				$rows = $query->fetchAll(PDO::FETCH_ASSOC);
				if ($query->rowCount() == 0)
					$rows = array();
				foreach ($rows as $key => $comment) {
					if ($comment['user_id'])
					{
						$query = $account->getDB()->prepare("SELECT * FROM users WHERE id=:user_id");
						$query->execute(array(":user_id" => $comment['user_id']));
						$row = $query->fetch(PDO::FETCH_ASSOC);
						if ($query->rowCount() != 0)
							$rows[$key]['username'] = $row['username'];
					}
				}
				exit(json_encode(response(true, "Successfully retrieved comments.", $rows)));
			}
			catch(PDOException $ex)
			{
				exit(json_encode(response(false, $ex->getMessage(), "")));
			}
		}
		elseif ($_POST['action'] == "newComment" && isset($_POST['id']) && $_POST['id'] != "" && is_numeric($_POST['id']) && isset($_POST['comment']) && $_POST['comment'] != "")
		{
			$user_id = $account->isLoggedIn();
			if (isset($user_id['error']))
				exit(json_encode(response(false, "[C001] You are not logged in.", "")));
			$user_id = $user_id['data'];
			try
			{
				$query = $account->getDB()->prepare("INSERT INTO comments (img_id, user_id, comment) VALUES (:img_id, :user_id, :comment)");
				$query->execute(array(":img_id" => $_POST['id'], ":user_id" => $user_id, ":comment" => $_POST['comment']));
				if ($query->rowCount() == 0)
					exit(json_encode(response(false, "[C002] An error occured. Try again, if this issues persists, contact an Administrator.", "")));
				$query = $account->getDB()->prepare("SELECT * FROM images WHERE id=:img_id");
				$query->execute(array(":img_id" => $_POST['id']));
				$row_img = $query->fetch(PDO::FETCH_ASSOC);
				if ($query->rowCount() != 0)
				{
					$query = $account->getDB()->prepare("SELECT * FROM users WHERE id=:user_id");
					$query->execute(array(":user_id" => $row_img['user_id']));
					$row_user = $query->fetch(PDO::FETCH_ASSOC);
					if ($query->rowCount() != 0)
						$to = $row_user['email'];
						$subject = "New comment on one of your pictures !";
						$message = "Someone commented on your picture '".$row_img['title'];
						$headers = "From: no-reply@camagru.itokoyamato.net";

						mail($to, $subject, $message, $headers);
				}
				
				exit(json_encode(response(true, "Successfully added comments.", "")));
			}
			catch(PDOException $ex)
			{
				exit(json_encode(response(false, $ex->getMessage(), "")));
			}
		}
		else
			exit(json_encode(response(false, "[C003] Invalid request.", "")));
	}
	else
		exit(json_encode(response(false, "[C004] Invalid request.", "")));
?>