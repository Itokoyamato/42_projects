ip=`ifconfig | grep "inet " | cut -d ' ' -f2`
ip_nbr=`ifconfig | grep "inet " | cut -d ' ' -f2 | wc -l | tr -d ' '`

if [ "$ip_nbr" -eq "0" ]; then
	echo "Je suis perdu!\n"
else
	echo "$ip"
fi
