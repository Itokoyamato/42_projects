RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color
i=0
k=1
j=1
echo "${RED}*****************************\n*****************************\n"
echo "${NC}[${GREEN}Testing errors${NC}]"
echo "" | ./colle-2
echo "o--"| ./colle-2
echo "o--o\n|ui|" | ./colle-2
echo "salkjasd" | ./colle-2
echo "o--o\nsfd" | ./colle-2
while [ $i -le 4 ]
do
	echo "${NC}\n[${GREEN}Testing colle0$i${NC}]"
	j=`expr 1`
	while [ $j -le 10 ]
	do
		k=`expr 1`
		while [ $k -le 10 ]
		do
			../colle0$i $j $k | ../ex00/colle-2
			k=`expr $k + 1`
		done
		j=`expr $j + 1`
	done
	i=`expr $i + 1`
done