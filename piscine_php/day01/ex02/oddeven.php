#!/usr/bin/php
<?php
	while(1){
		echo "Entrez un nombre: ";
		if (!$input = fgets(STDIN))
			exit ("^D\n");
		$input = substr_replace($input, "", -1);
		if (!is_numeric($input))
			echo "'$input' n'est pas un chiffre\n";
		else
		{
			$input = trim($input);
			if ((int)$input % 2)
				echo "Le chiffre $input est Impair\n";
			else
				echo "Le chiffre $input est Pair\n";
		}
	}
?>