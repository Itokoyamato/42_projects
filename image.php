<?php
	include_once "account.php";
	include_once "count.php";
	if (isset($_POST['action']) && $_POST['action'] != "" && isset($_POST['token']) && $_POST['token'] != "")
	{
		$user_id = $account->isLoggedIn($_POST['token']);
		if (isset($user_id['error']))
			exit(json_encode(response(false, "[I001] You are not logged in.")));
		$user_id = $user_id['data'];
		if ($_POST['action'] == "like" && isset($_POST['id']) && $_POST['id'] != "")
		{
			try
			{
				$query = $account->getDB()->prepare("SELECT * FROM likes WHERE img_id=:img_id AND user_id=:user_id");
				$query->execute(array(":img_id" => $_POST['id'], ":user_id" => $user_id));
				if ($query->rowCount() == 0)
				{
					$query = $account->getDB()->prepare("INSERT INTO likes (img_id, user_id, date_liked) VALUES (:img_id, :user_id, NOW())");
					$query->execute(array(":img_id" => $_POST['id'], ":user_id" => $user_id));
					if ($query->rowCount() == 0)
						exit(json_encode(response(false, "[I002] An error occured. Try again, if this issues persists, contact an Administrator.")));
					exit(json_encode(response(true, "Successfully liked.", array(true, count_likes($_POST['id'])['data']))));
				}
				else
				{
					$query = $account->getDB()->prepare("DELETE FROM likes WHERE img_id=:img_id AND user_id=:user_id");
					$query->execute(array(":img_id" => $_POST['id'], ":user_id" => $user_id));
					if ($query->rowCount() == 0)
						exit(json_encode(response(false, "[I003] An error occured. Try again, if this issues persists, contact an Administrator.")));
					exit(json_encode(response(true, "Successfully unliked.", array(false, count_likes($_POST['id'])['data']))));
				}
				exit(json_encode(response(false, "[I004] An error occured. Try again, if this issues persists, contact an Administrator.")));
			}
			catch(PDOException $ex)
			{
				exit(json_encode(response(false, $ex->getMessage())));
			}
			exit(json_encode(response(false, "[I005] An error occured. Try again, if this issues persists, contact an Administrator.")));
		}
		else
			exit(json_encode(response(false, "[I006] Invalid request.")));
	}
	elseif (isset($_POST['token']) && $_POST['token'] == "")
		exit(json_encode(response(false, "[I007] You are not logged in.")));
	else
		exit(json_encode(response(false, "[I008] Invalid request.")));
?>