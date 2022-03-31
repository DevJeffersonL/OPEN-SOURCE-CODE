#Declaring Global variable 
import os 
sum=0
n=1000
count=1
def func():
	while count<n:
		if(count%3==0 or count%5==0):
			sum+=count
func()
print(sum)
os.system('pause >nul')