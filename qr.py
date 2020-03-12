import numpy as np 
import math

A=np.array([[5,-2],[-2,8]])

x1,x2=np.linalg.eigh(A)


while abs(A[0,1])>=10**-10 or abs(A[1,0])>=10**-10:
	q,r=np.linalg.qr(A)
	A=np.matmul(r,q)
qr1=A[0,0]
qr2=A[1,1]

print(qr1,qr2)
print(x1,x2)



