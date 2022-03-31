def func():
	count=0;n=1000; s=0 
	while count<n:
		if(count%3==0 or count%5==0):
			s+=count
		count+=1
	print(s)
func()