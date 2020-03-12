import numpy as np

A=np.array([[1,0.67,0.33],[0.45,1,0.55],[0.67,0.33,1]])
print(A)

B=np.array([[2],[2],[2]])
print(B)

x=np.linalg.solve(A,B)
print(x)



