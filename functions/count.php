<?php
	include_once $_SERVER['DOCUMENT_ROOT']."/camagru/config/config.php";
	include_once PATH_FT."account.php";

	function count_likes($id)
	{
		try
		{
			$account = new Account();
			$query = $account->getDB()->prepare("SELECT COUNT(*) AS likes FROM likes WHERE img_id=:img_id");
			$query->execute(array(":img_id" => $id));
			$count_likes = $query->fetch(PDO::FETCH_ASSOC)['likes'];
			return(response(true, "Successfully retrieved likes.", $count_likes));
		}
		catch(PDOException $ex)
		{
			return(response(false, $ex->getMessage(), ""));
		}
	}

	function count_comments($id)
	{
		try
		{
			$account = new Account();
			$query = $account->getDB()->prepare("SELECT COUNT(*) AS comments FROM comments WHERE img_id=:img_id");
			$query->execute(array(":img_id" => $id));
			$count_comments = $query->fetch(PDO::FETCH_ASSOC)['comments'];
			return(response(true, "Successfully retrieved comments.", $count_comments));
		}
		catch(PDOException $ex)
		{
			return(response(false, $ex->getMessage(), ""));
		}
	}

	function didUserLike($img_id, $user_id)
	{
		try
		{
			$account = new Account();
			$query = $account->getDB()->prepare("SELECT * FROM likes WHERE img_id=:img_id AND user_id=:user_id");
			$query->execute(array(":img_id" => $img_id, ":user_id" => $user_id));
			if ($query->rowCount() == 0)
				return(response(true, "Successfully retrieved like.", false));
			else
				return(response(true, "Successfully retrieved like.", true));
		}
		catch(PDOException $ex)
		{
			return(response(false, $ex->getMessage(), ""));
		}
	}
?>