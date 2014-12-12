r = int(raw_input())

for v in range(1,r+1):
	n = int(raw_input())
	i = 0

	#while i < n:
	#	(raw_input())
	#	arr.append(c)
	#	i+=1
	st = raw_input()
	arr = st.split(' ')
	s=0
	for i in range(0,n):
		for j in range(i+1,n):
			if(int(arr[i])*int(arr[j]) > int(arr[i])+int(arr[j])):
				s+=1
	print s			
