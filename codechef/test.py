import random
a = int(raw_input())
for i in range(a):
	x=random.randint(1,100)
	arr=[]
	for y in range(x):
		arr.append(0)
	for y in range(x):
		for z in range(y):
			arr[z]= (arr[z]+1)%2
	count=0
	for y in arr:
	  if y==0:
	  	count=count+1
	if(count != x/2+1 and x%2!=0)  :
		print "no"
		#print "x was " + str(x)
	
	if(count == x/2 and x%2!=0):
		print "no"


	#print x
	#print count

	#print "-------"

