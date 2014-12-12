g++ INTEG.cpp -o me
g++ yash.cpp -o ysh


for (( i=0 ; i <=100;i++))
do	
	python test.py > inp
	./me < inp > outme
	./ysh < inp > outysh
	diff outme outysh > output
done
