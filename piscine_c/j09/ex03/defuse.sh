unix=$(stat -f "%m" bomb.txt)
expr $unix - 1