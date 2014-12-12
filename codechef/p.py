n = 3000002
print
print "LL fact[]={1,",
ans=1
i=1
while i < n-1:
	ans = (ans*(i%3046201))%3046201
	print str(ans)+",",
	i+=1
ans = (ans*(n%3046201))%3046201	
print str(ans)+"};"	
