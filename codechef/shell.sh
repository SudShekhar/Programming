for i in {1..5}
do
	#echo g++ ws.cpp -o t$i
	echo "test "+ $i
	python ge.py  > in
	 ./seg < in > o1
	 ./norm < in  > o2
	 diff o1 o2 >> FINAL
done
