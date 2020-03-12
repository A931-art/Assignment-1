import numpy as np 
import math

A=np.array([[0.2,0.1,1,1,0],[0.1,4,-1,1,-1],[1,-1,60,0,-2],[1,1,0,8,4],[0,-1,-2,4,700]])
B=np.array([1.0,2.0,3.0,4.0,5.0])

x=np.array([0.0,0.0,0.0,0.0,0.0]) 
s=np.array([7.85971307,0.422926408,-0.073592239,-0.540643016,0.010626163]) 

count=0 
w=1.25 

while abs(s[0])>=0.01 or abs(s[1])>=0.01 or abs(s[2])>=0.01 or abs(s[3])>=0.01 or abs(s[4])>=0.01:
	s=np.array([7.85971307,0.422926408,-0.073592239,-0.540643016,0.010626163]) 
	y=np.array([0.0,0.0,0.0,0.0,0.0])
	rv=np.array([0.0,0.0,0.0,0.0,0.0]) 
	for i in range(5):
		for j in range(5):
			y[i]=y[i]-(A[i,j]*x[j])
			
		rv[i]=y[i]+B[i]
		x[i]=x[i]+w*rv[i]/A[i,i]		
		s[i]=s[i]-x[i]
	count=count+1	


print(count)	
print(x)
print(s)
	
