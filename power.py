import numpy as np

A=np.array([[2.0,-1.0,0.0],[-1.0,2.0,-1.0],[0.0,-1.0,2.0]])
x=np.array([1,1,1])

flag=0.1

vec=np.matmul(A,x)

pv=np.matmul(np.transpose(vec),vec)
nv=np.matmul(np.transpose(np.matmul(A,vec)),vec)

plam=nv/pv

while(abs(flag)>0.01):
	vec=np.matmul(A,vec)
	pv=np.matmul(np.transpose(vec),vec)
	nv=np.matmul(np.transpose(np.matmul(A,vec)),vec)
	nlam=nv/pv

        eigenvector=vec
        norm=np.linalg.norm(eigenvector)
        eigenvector_norm=eigenvector/norm
	flag=plam-nlam
	plam=nlam

print(nlam)
print(eigenvector_norm)



