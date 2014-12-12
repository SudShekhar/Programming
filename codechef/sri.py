import math

re=int (raw_input())
#for (v=0 ; v<re;v++):
for v in range(re):
	n=int(raw_input())
	lst={}
	deg={}
	money={}
	for i in range((n-1)):
		st = raw_input()
		arr=st.split()
	#	print arr
	#	if arr[1] in lst.keys() :
	#		deg[arr[1]]+=1
	#		money[arr[0]] = arr[2]
	#		lst[arr[0]]=arr[1]
	#	elif arr[0] in lst.values():
	#			deg[arr[0]]+=1
	
		lst[arr[0]]=arr[1]
		if deg.has_key(arr[0]):
			del deg[arr[0]]
		else:	
			deg[arr[0]]=1
		if deg.has_key(arr[1]):
			del deg[arr[1]]
		else: deg[arr[1]]=1
	
		money[arr[0]]=arr[2]
	
#	print lst
#	print money
	for i in deg.iterkeys():
		if i not in lst.values():
			try:
				while 1:
					print i + " " + lst[i] + " " + money[i]
					i = lst[i]
			except KeyError :
				
					break
	s=0
#	print str( reduce(lambda x,y: int(x.strip('$')) +int(y.strip('$')) ,money.values()))+'$'		
	for x in money.values():
		s+=int(x.strip('$'))
	print str(s) + '$'	
