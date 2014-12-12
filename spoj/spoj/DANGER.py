#!/bin/python

from math import log
while(1):
	a = raw_input();
	n = int(a[0])*10+ int(a[1]);
	l = len(a);
	n = n* 10**(int(a[3]));
	if n ==0: break
#n = int(raw_input());
	print 2*(n - 2**(int(log(n,2)))) + 1
#return 0	
