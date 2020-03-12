import numpy as np
import time

A=np.array([[0, 1, 1], [0, 1, 0], [1, 1, 0], [0, 1, 0], [1, 0, 1]])

start_time1=time.time()

ev1,U=np.linalg.eigh(np.dot(A,np.transpose(A)))
sev_1=ev1.argsort()[::-1]
U=U[:,sev_1]

ev2,V=np.linalg.eigh(np.dot(np.transpose(A),A))
sev_2=ev2.argsort()[::-1]
V=V[:,sev_2]

S=np.dot(np.dot(np.transpose(U),A),V)
print("U:\n",U,"\n S:\n",S,"\n V:\n",V)
print("Time required = ",(time.time()-start_time1))

start_time2=time.time()
Up,Sp,Vp=np.linalg.svd(A)

print("SVD form using np.linalg.svd: \n")
print(Up)
print(Sp)
print(Vp)

print("Time required: ",(time.time()-start_time2))
