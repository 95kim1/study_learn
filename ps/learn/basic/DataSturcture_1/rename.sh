flag=0
B="";
C="";
for f in $@;
do	
	if [ $f = "[boj" ]
	then	
		if (( $flag==1 ))
		then
			D=$((${#C}-3))
			C=${C: 0:$D}
		else
			flag=1
		fi
		echo $C
		B="${B}${C} "
		C=""
	fi
	C=$C$f
done
D=$((${#C}-3))
C=${C: 0:$D}
B="${B}${C} "

for f in $B;
do
	S="${f}.md"
	D="${f}.cpp"
	mv $S $V
done

exit
