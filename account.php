<?php
	include("./database.php");
	class Account {
		private $username;
		private $password;
		private $email;
		private $db;

		public function __construct(array $kwargs) {
			if (array_key_exists("username", $kwargs))
				$this->username = $kwargs['username'];
			if (array_key_exists("email", $kwargs))
				$this->email = $kwargs['email'];
			if (array_key_exists("password", $kwargs))
				$this->password = hash("whirlpool", $kwargs['password']);
			$this->db = init_db();
		}
		
		public function login()
		{
			try
			{
				$query = $this->db->prepare("SELECT * FROM users WHERE username=:username");
				$query->execute(array(":username"=>$this->username));
				$row=$query->fetch(PDO::FETCH_ASSOC);
				if ($query->rowCount() > 0)
				{
					if ($row["password"] == $this->password)
						return (1);
					else
						return (2);
				}
				else
					return (2);
			}
			catch(PDOException $ex)
			{
				return $ex->getMessage();
			}
		}
		
		public function logout()
		{
			session_destroy();
			$_SESSION["data"] = false;
		}

		public function isUserExist() {
			$query = $this->db->prepare('SELECT * FROM users WHERE username=:username');
			$query->execute(array(":username" => $this->username));
			$count = $query->rowCount();
			if ($count != 0) {
				return true;
			}
			return false;
		}

		public function isEmailExist() {
			$query = $this->db->prepare('SELECT * FROM users WHERE email=:email');
			$query->execute(array(":email" => $this->email));
			$count = $query->rowCount();
			if ($count != 0) {
				return true;
			}
			return false;
		}

		public function register() {
			if ($this->isUserExist())
				return (2);
			if ($this->isEmailExist())
				return (3);
			try
			{
				$query = $this->db->prepare("INSERT INTO users (username, email, password) VALUES (:username, :email, :password)");
				$query->execute(array(":username" => $this->username, ":email" => $this->email, ":password" => $this->password));
				return (1);
			}
			catch(PDOException $ex)
			{
				return $ex->getMessage();
			}
			// echo "test";
			// send_mail($this->email,"Bienvenue", $message);
		}

		public function toString() {
			return $this->$username;
		}
	}
?>