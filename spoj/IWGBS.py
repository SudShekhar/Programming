#!/bin/python
n = int(raw_input())
if n <2: print n
else:
	a1 =1
	a2 = 2
	for i in range(2,n+1):
		ans = a1+a2
		a1 = a2
		a2 = ans
	print ans	

