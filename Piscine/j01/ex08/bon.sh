ldapsearch dn | grep dn | sed -e "s/dn: uid=.//" -e "s/,.*//g" | grep bon | wc -l | sed "s/      //g"