#!/bin/python
mx = 0
for i in range(1,100):
	for j in range(1,100):
		s = i**j
		st = str(s)
		ans = reduce(lambda x,y: x+ int(y),st,0)
		if ans> mx:
			mx = ans
print mx
