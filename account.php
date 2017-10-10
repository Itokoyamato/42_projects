<?php
	include_once "./database.php";
	class Account {
		private $db;

		public function __construct() {
			$this->db = init_db();
		}
		
		public function login($username, $password)
		{
			try
			{
				$query = $this->db->prepare("SELECT * FROM users WHERE username=:username");
				$query->execute(array(":username" => $username));
				$row = $query->fetch(PDO::FETCH_ASSOC);
				if ($query->rowCount() > 0)
				{
					if ($row["password"] == hash("whirlpool", $password))
					{
						$token = bin2hex(mcrypt_create_iv(22, MCRYPT_DEV_URANDOM));
						setcookie("camagru_token", $token, time() + 3600);
						$query = $this->db->prepare("INSERT INTO users_sessions (username, token, timestamp_added, timestamp_expire) VALUES (:username, :token, NOW(), TIMESTAMPADD(SECOND, 3600, now()))");
						$query->execute(array(":username" => $username, ":token" => $token));
						return (1);
					}
					else
						return (2);
				}
				else
					return (2);
			}
			catch(PDOException $ex)
			{
				return ($ex->getMessage());
			}
		}
		
		public function logout()
		{
			if (isset($_COOKIE['camagru_token']) && $_COOKIE['camagru_token'] != "")
			{
				$query = $this->db->prepare("DELETE FROM users_sessions WHERE token=:token");
				$query->execute(array(":token" => $_COOKIE['camagru_token']));
			}
			session_destroy();
			setcookie("camagru_token", "", 1);
			$_SESSION['user-session'] = false;
			return (true);
		}

		public function isLoggedIn()
		{
			if (isset($_COOKIE['camagru_token']) && $_COOKIE['camagru_token'] != "")
			{
				// return ("bruh");
				$token = $_COOKIE['camagru_token'];
				$query = $this->db->prepare("SELECT * FROM users_sessions WHERE token=:token");
				$query->execute(array(":token" => $token));
				$row = $query->fetch(PDO::FETCH_ASSOC);
				if ($query->rowCount() > 0)
				{
					if ($row["timestamp_expire"] < date("Y-m-d H:i:s"))
					{
						$query = $this->db->prepare("DELETE FROM users_sessions WHERE token=:token");
						$query->execute(array(":token" => $token));
						$this->logout();
						return (false);
					}
					else
					{
						$_SESSION['username'] = $row["username"];
						return (true);
					}
				}
			}
			return (false);
		}

		public function isUserExist($username) {
			$query = $this->db->prepare('SELECT * FROM users WHERE username=:username');
			$query->execute(array(":username" => $username));
			if ($query->rowCount() != 0) {
				return (true);
			}
			return (false);
		}

		public function isEmailExist($email) {
			$query = $this->db->prepare('SELECT * FROM users WHERE email=:email');
			$query->execute(array(":email" => $email));
			if ($query->rowCount() != 0) {
				return (true);
			}
			return (false);
		}

		public function register($username, $email, $password) {
			if ($this->isUserExist($username))
				return (2);
			if ($this->isEmailExist($email))
				return (3);
			try
			{
				$query = $this->db->prepare("INSERT INTO users (username, email, password) VALUES (:username, :email, :password)");
				$query->execute(array(":username" => $username, ":email" => $email, ":password" => hash("whirlpool", $password)));
				if ($query->rowCount() != 0)
				{
					$this->new_validation_token($username, $email, $password);
					return (1);
				}
				else
					return (4);
			}
			catch(PDOException $ex)
			{
				return ($ex->getMessage());
			}
			// echo "test";
			// send_mail($this->email,"Bienvenue", $message);
		}

		public function new_validation_token($username, $email, $password) {
			try
			{
				$token = bin2hex(mcrypt_create_iv(22, MCRYPT_DEV_URANDOM));
				$query = $this->db->prepare("INSERT INTO users_register_token (username, token, timestamp_added, timestamp_expire) VALUES (:username, :token, NOW(), TIMESTAMPADD(SECOND, 3600, now()))");
				$query->execute(array(":username" => $username, "token" => $token));
				if ($query->rowCount() != 0)
				{
					return (true);
				}
				else
					return (false);
			}
			catch(PDOException $ex)
			{
				return ($ex->getMessage());
			}
		}

		public function validate($token) {
			try
			{
				$query = $this->db->prepare("SELECT * FROM users WHERE register_token = :token");
				$query->execute(array(":token" => $token));
				$row = $query->fetch(PDO::FETCH_ASSOC);
				if ($query->rowCount() > 0)
				{
					$user_id = $row["id"];
					$query = $this->db->prepare("UPDATE users SET register_token = NULL WHERE id = :user_id");
					$query->execute(array(":user_id" => $user_id));
				}
				else
					return (1);
			}
			catch(PDOException $ex)
			{
				return ($ex->getMessage());
			}
		}

		public function toString() {
			return "hi";
		}
	}
?>