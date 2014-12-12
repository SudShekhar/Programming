import random
n = random.randint(1,100)
i=0
print n
while i<n:
	a = random.randint(1,1000)
	b = random.randint(1,1000)
	c = random.randint(1,100)
	print a,b,c
	for j in range(b):
		print num,
		num = random.randint(num-100,num+100)
	print
	i+=1
