import numpy as np


A=np.array([[0.2,0.1,1.0,1.0,0.0],[0.1,4.0,-1.0,1.0,-1.0],[1.0,-1.0,60.0,0.0,-2.0],[1.0,1.0,0.0,8.0,4.0],[0.0,-1.0,-2.0,4.0,700.0]])
B=np.array([1.0,2.0,3.0,4.0,5.0])

xsol=np.array([7.859713071,0.422926408,-0.073592239,-0.540643016,0.010626163])
x=np.zeros(5)

count=0
flag=0
i=0

while ( flag!=5 ):
	v=2*B-2*np.matmul(A,x)
	t=(np.matmul(np.transpose(v),v/2))/(np.matmul(np.transpose(v),np.matmul(A,v)))
	x=x+t*v
	#print(x)
	flag=0
	for i in range(0,5):
		if abs(x[i]-xsol[i])<0.01:
			flag=flag+1
	count=count+1

print(x)
print(count)
print(flag)	

