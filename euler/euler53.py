#!/bin/python

l=[]
l.append(1)
for i in range(1,101):
	l.append(l[i-1]*i)

md = 1000000
cnt=0
for i in range(1,101):
	for j in range(1,(i+1)):
		ans = l[i] / (l[i-j]*l[j])
		if ans > md:
			cnt+=1

print cnt
