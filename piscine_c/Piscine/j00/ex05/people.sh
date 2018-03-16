ldapsearch -LLL -x "uid=z*" cn| grep -v "^dn: " | sed -n 's/^[ \t]*cn:[ \t]*\(.*\)/\1/p' | sort -r -f
