<?PHP
Class Color {
	public static $verbose = false;
	public $r = 0;
	public $g = 0;
	public $b = 0;

	public static function doc() {
		print (file_get_contents("./Color.doc.txt"));
		return;
	}

	public function __construct(array $kwargs) {
		if (array_key_exists("red", $kwargs))
			$this->r = $kwargs['red'] % 256;
		if (array_key_exists("blue", $kwargs))
			$this->b = $kwargs['blue'] % 256;
		if (array_key_exists("green", $kwargs))
			$this->g = $kwargs['green'] % 256;
		if (array_key_exists("rgb", $kwargs))
			{
				$this->r = ($kwargs['rgb'] >> 16) % 256;
				$this->g = ($kwargs['rgb'] >> 8) % 256;
				$this->b = $kwargs['rgb'] % 256;
			}
		if (self::$verbose == true)
			printf( 'Color( red: %3d, green: %3d, blue: %3d ) constructed.'.PHP_EOL, $this->r, $this->g, $this->b);
		return;
	}

	public function __destruct() {
		if (self::$verbose == true)
		printf( 'Color( red: %3d, green: %3d, blue: %3d ) destructed.'.PHP_EOL, $this->r, $this->g, $this->b);
		return;
	}

	public function __toString() {
		return (sprintf( 'Color( red: %3d, green: %3d, blue: %3d )', $this->r, $this->g, $this->b));
	}

	public function add( Color $instance ) {
		return (new Color( array( 'red' => $this->r + $instance->r, 'green' => $this->g + $instance->g, 'blue' => $this->b + $instance->b)));
	}
	
	public function sub( Color $instance ) {
		return (new Color( array( 'red' => $this->r - $instance->r, 'green' => $this->g - $instance->g, 'blue' => $this->b - $instance->b)));
	}
	
	public function mult( $nb ) {
		return (new Color( array( 'red' => $this->r * $nb, 'green' => $this->g * $nb, 'blue' => $this->b * $nb)));
	}
}
?>