<?php
	include_once "./config/database.php";
	function echo_r($msg)
	{
		echo ($msg);
		exit();
	}
	function response($success, $msg)
	{
		if (!$success)
			return (array(
				"error" => true,
				"message" => $msg
			));
		else
			return (array(
				"message" => $msg
			));
	}
	function strclean($str)
	{
		return (htmlspecialchars(strip_tags(trim($str))));
	}
	class Account {
		private $db;

		public function __construct() {
			$this->db = init_db();
		}

		public function getDB()
		{
			return ($this->db);
		}
		
		public function login($username, $password)
		{
			$username = strclean($username);
			$password = strclean($password);
			try
			{
				// Retrieve account using username
				$query = $this->db->prepare("SELECT * FROM users WHERE username=:username");
				$query->execute(array(":username" => $username));
				$row = $query->fetch(PDO::FETCH_ASSOC);
				if ($query->rowCount() > 0)
				{
					// Check if password matches
					if ($row["password"] == hash("whirlpool", $password))
					{
						if ($row["active"] != 1)
							return (response(false, "Your account is not yet activated. Check your emails for an activation link."));
						// Generate session token
						$token = bin2hex(mcrypt_create_iv(22, MCRYPT_DEV_URANDOM));
						$user_id = $row['id'];
						setcookie("camagru_token", $token, time() + 3600);
						// Save session token
						$query = $this->db->prepare("INSERT INTO users_sessions (user_id, token, timestamp_added, timestamp_expire) VALUES (:user_id, :token, NOW(), TIMESTAMPADD(SECOND, 3600, now()))");
						$query->execute(array(":user_id" => $user_id, ":token" => $token));

						return (response(true, "You have successfully logged in."));
					}
					else
						return (response(false, "Invalid credentials."));
				}
				else
					return (response(false, "Invalid credentials."));
			}
			catch(PDOException $ex)
			{
				return (response(false, $ex->getMessage()));
			}
			return (response(false, "An error occured [A001]. Please try again. If this error persists, contact an Administrator."));
		}
		
		public function logout()
		{
			// Check if session is active
			if (isset($_COOKIE['camagru_token']) && $_COOKIE['camagru_token'] != "")
			{
				$token = strclean($_COOKIE['camagru_token']);
				try
				{
					// De-activate session token in database
					$query = $this->db->prepare("UPDATE users_sessions SET active = 0 WHERE token=:token");
					$query->execute(array(":token" => $token));
				}
				catch(PDOException $ex)
				{
					return (response(false, $ex->getMessage()));
				}
			}
			// Delog
			session_destroy();
			setcookie("camagru_token", "", 1);
			$_SESSION['user-session'] = false;
			return (response(true, "You have successfully logged off."));
		}

		public function isLoggedIn()
		{
			// Check if session is active
			if (isset($_COOKIE['camagru_token']) && $_COOKIE['camagru_token'] != "")
			{
				$token = strclean($_COOKIE['camagru_token']);
				try
				{
					// Check if session is valid
					$query = $this->db->prepare("SELECT * FROM users_sessions WHERE token=:token");
					$query->execute(array(":token" => $token));
					$row = $query->fetch(PDO::FETCH_ASSOC);
					if ($query->rowCount() > 0)
					{
						// Check if session expired
						if ($row["timestamp_expire"] < date("Y-m-d H:i:s"))
						{
							$query = $this->db->prepare("UPDATE users_sessions SET active = 0 WHERE token=:token");
							$query->execute(array(":token" => $token));
							$this->logout();
							return (response(false, "Your session token expired."));
						}
						elseif ($row["active"] == 0)
							return (response(false, "Your session token expired"));
						else
						{
							// $_SESSION['username'] = $row["username"];
							return (response(true, "You are logged in."));
						}
					}
					else
						return (response(false, "You are not logged in."));
				}
				catch(PDOException $ex)
				{
					return (response(false, $ex->getMessage()));
				}
			}
			return (response(false, "You are not logged in."));
		}

		public function isUsernameAvailable($username) {
			$username = strclean($username);
			try
			{
				$query = $this->db->prepare('SELECT * FROM users WHERE username=:username');
				$query->execute(array(":username" => $username));
				if ($query->rowCount() != 0)
					return (response(false, "Username is already taken."));
				else
					return (response(true, "Username is available."));
			}
			catch(PDOException $ex)
			{
				return (response(false, $ex->getMessage()));
			}
			return (response(false, "An error occured [A002]. Please try again. If this error persists, contact an Administrator."));
		}

		public function isEmailAvailable($email) {
			$email = strclean($email);
			try
			{
				$query = $this->db->prepare('SELECT * FROM users WHERE email=:email');
				$query->execute(array(":email" => $email));
				if ($query->rowCount() != 0)
					return (response(false, "Email is already in use."));
				else
					return (response(true, "Email is available."));
			}
			catch(PDOException $ex)
			{
				return (response(false, $ex->getMessage()));
			}
			return (response(false, "An error occured [A003]. Please try again. If this error persists, contact an Administrator."));
		}

		public function register($username, $email, $password) {
			$username = strclean($username);
			$email = strclean($email);
			$password = strclean($password);
			//Check if data is valid
			if (empty($username) || empty($email) || empty($password))
				return (response(false, "Invalid username, email or password."));
			if (!preg_match('/^\w{5,}$/', $username))
				return (response(false, "Invalid username. Must be alphanumeric and at least 5 characters long."));
			if (!filter_var($email, FILTER_VALIDATE_EMAIL))
				return (response(false, "Invalid email."));
			if (strlen($password) < 7 || !preg_match("#[0-9]+#", $password) || !preg_match("#[A-Z]+#", $password) || !preg_match("#[a-z]+#", $password))
				return (response(false, "Invalid password. Must be at least 7 characters long, contain an uppercase letter, a lowercase letter and a number."));
			
			// Check if username or email is already used
			$userExists = $this->isUsernameAvailable($username);
			$emailExists = $this->isEmailAvailable($email);
			if (isset($userExists['error']))
				return (response(false, $userExists['message']));
			if (isset($emailExists['error']))
				return (response(false, $emailExists['message']));
			
			try
			{
				// Create account
				$query = $this->db->prepare("INSERT INTO users (username, email, password) VALUES (:username, :email, :password)");
				$query->execute(array(":username" => $username, ":email" => $email, ":password" => hash("whirlpool", $password)));
				if ($query->rowCount() != 0)
				{
					// Generate activation token
					$activation = $this->new_activation_token($this->db->lastInsertId(), $email);
					if (isset($activation['error']))
						return (response(false, "You have successfully registered. ".$validation['message']));
					else
						return (response(true, "You have successfully registered."));
				}
				else
					return (response(false, "An error occured [A004]. Please try again. If this error persists, contact an Administrator."));
			}
			catch(PDOException $ex)
			{
				return (response(false, $ex->getMessage()));
			}
			return (response(false, "An error occured [A005]. Please try again. If this error persists, contact an Administrator."));
		}

		public function new_activation_token($user_id, $email) {
			$user_id = strclean($user_id);
			$email = strclean($email);
			try
			{
				// Generate token and save it
				$token = bin2hex(mcrypt_create_iv(22, MCRYPT_DEV_URANDOM));
				$query = $this->db->prepare("INSERT INTO users_register_token (user_id, token, timestamp_added, timestamp_expire) VALUES (:user_id, :token, NOW(), TIMESTAMPADD(SECOND, 3600, now()))");
				$query->execute(array(":user_id" => $user_id, "token" => $token));
				if ($query->rowCount() != 0)
				{
					// Send email
					$to = $email;
					$subject = 'Camagru account activation';
					$message = '"Activation token: ".$token';
					$headers = 'From: no-reply@camagru.itokoyamato.net';

					mail($to, $subject, $message, $headers);
					// mail($email, "Camagru test activation token", "Activation token: ".$token);
					return (response(true, "New activation token successfully created."));
				}
				else
					return (response(false, "An error occured [A005]. Please try again. If this error persists, contact an Administrator."));
			}
			catch(PDOException $ex)
			{
				return (response(false, $ex->getMessage()));
			}
			return (response(false, "An error occured [A006]. Please try again. If this error persists, contact an Administrator."));
		}

		public function activateAccount($token) {
			$token = strclean($token);
			try
			{
				if ($token == "")
					return (response(false, "This activation token is invalid."));
				// Retrieve token
				$query = $this->db->prepare("SELECT * FROM users_register_token WHERE token = :token");
				$query->execute(array(":token" => $token));
				$row = $query->fetch(PDO::FETCH_ASSOC);
				if ($query->rowCount() > 0)
				{
					// Check if expired
					if ($row["timestamp_expire"] < date("Y-m-d H:i:s") || $row["used"] == 1)
						return (response(false, "This activation token has expired."));

					$user_id = $row["user_id"];

					// Check if account is already activated
					$query = $this->db->prepare("SELECT * FROM users WHERE id = :user_id");
					$query->execute(array(":user_id" => $user_id));
					$row = $query->fetch(PDO::FETCH_ASSOC);
					if ($query->rowCount() > 0 && $row["active"] == 1)
						return (response(false, "This account is already activated."));

					// Activate account
					$query = $this->db->prepare("UPDATE users SET active = 1 WHERE id = :user_id");
					$query->execute(array(":user_id" => $user_id));
					if ($query->rowCount() != 0)
					{
						$query = $this->db->prepare("UPDATE users_register_token SET used = 1 WHERE user_id = :user_id");
						$query->execute(array(":user_id" => $user_id));
						if ($query->rowCount() != 0)
							return (response(true, "You have successfully activated your account."));
						else
							return (response(false, "An error occured [A007]. Please try again. If this error persists, contact an Administrator."));
					}
					else
						return (response(false, "An error occured [A008]. Please try again. If this error persists, contact an Administrator."));
				}
				else
					return (response(false, "This activation token is invalid."));
			}
			catch(PDOException $ex)
			{
				return (response(false, $ex->getMessage()));
			}
		}

		function resetPass_send($email)
		{
			$email = strclean($email);
			try
			{
				// Check if email is used
				$query = $this->db->prepare("SELECT * FROM users WHERE email = :email");
				$query->execute(array(":email" => $email));
				$row = $query->fetch(PDO::FETCH_ASSOC);
				if ($query->rowCount() > 0)
				{
					// Generate token and save it
					$token = bin2hex(mcrypt_create_iv(22, MCRYPT_DEV_URANDOM));
					$query = $this->db->prepare("INSERT INTO users_reset_password_token (user_id, token, timestamp_added, timestamp_expire) VALUES (:user_id, :token, NOW(), TIMESTAMPADD(SECOND, 3600, now()))");
					$query->execute(array(":user_id" => $row['id'], ":token" => $token));
					if ($query->rowCount() != 0)
					{
						// Send email
						mail($email, "Camagru test reset token", "Reset token: ".$token);
						return (response(true, "New password-reset token successfully created."));
					}
					else
						return (response(false, "An error occured [A009]. Please try again. If this error persists, contact an Administrator."));
				}
				else
					return (response(false, "No account is registered to this email."));
			}
			catch(PDOException $ex)
			{
				return (response(false, $ex->getMessage()));
			}
		}

		function resetPass_check($token)
		{
			$token = strclean($token);
			try
			{
				if ($token == "")
					return (response(false, "This password-reset token is invalid."));
				// Retrieve token
				$query = $this->db->prepare("SELECT * FROM users_reset_password_token WHERE token = :token");
				$query->execute(array(":token" => $token));
				$row = $query->fetch(PDO::FETCH_ASSOC);
				if ($query->rowCount() > 0)
				{
					// Check if expired
					if ($row["timestamp_expire"] < date("Y-m-d H:i:s") || $row["used"] == 1)
						return (response(false, "This password-reset token has expired."));

					return (response(true, $row['user_id']));
				}
				else
					return (response(false, "This password-reset token is invalid."));
			}
			catch(PDOException $ex)
			{
				return (response(false, $ex->getMessage()));
			}
		}

		function resetPass_set($token, $password)
		{
			$token = strclean($token);
			$password = strclean($password);
			$isTokenValid = $this->resetPass_check($token);

			// Check if token is valid
			if (isset($isTokenValid['error']))
				return (response(false, $isTokenValid['message']));
			// Check is new password is valid
			if (strlen($password) < 7 || !preg_match("#[0-9]+#", $password) || !preg_match("#[A-Z]+#", $password) || !preg_match("#[a-z]+#", $password))
				return (response(false, "Invalid password. Must be at least 7 characters long, contain an uppercase letter, a lowercase letter and a number."));

			try
			{
				// Retrieve token
				$query = $this->db->prepare("UPDATE users SET password = :password WHERE id = :user_id");
				$query->execute(array(":user_id" => $isTokenValid["message"], ":password" => hash("whirlpool", $password)));
				if ($query->rowCount() != 0)
				{
					$query = $this->db->prepare("UPDATE users_reset_password_token SET used = 1 WHERE token = :token");
					$query->execute(array(":token" => $token));
					if ($query->rowCount() > 0)
						return (response(true, "You password has been changed successfully"));
					else
						return (response(false, "An error occured [A010]. Please try again. If this error persists, contact an Administrator."));
				}
				elseif ($query->rowCount() == 0)
					return (response(false, "Your new password is the same as the old password."));
				else
					return (response(false, "An error occured [A011]. Please try again. If this error persists, contact an Administrator."));
			}
			catch(PDOException $ex)
			{
				return (response(false, $ex->getMessage()));
			}
		}

		public function toString() {
			return "hi";
		}
	}
?>