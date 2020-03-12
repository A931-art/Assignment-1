#include <stdio.h>
#include <gsl/gsl_linalg.h>

int main()
{
    double A0[] = {1, 0.67, 0.33, 0.45, 1, 0.55, 0.67, 0.33, 1};
    int i,j,k;
    int flag = 0;

    gsl_matrix *M = gsl_matrix_alloc(3, 3);
    gsl_matrix *A = gsl_matrix_alloc(3, 3);

    printf("A = \n");
    for(i = 0;i<3;i=i+1)
    {
      for(j=0;j<3;j=j+1)
      {
        gsl_matrix_set(M,i,j,A0[i*3+j]);
        gsl_matrix_set(A,i,j,A0[i*3+j]);
        printf("%0.2f\t\t",A0[i*3+j]);
      }
      printf("\n");
    }
    printf("\n");

    int sign;
    gsl_permutation *p = gsl_permutation_alloc(3);


    gsl_linalg_LU_decomp(M, p, &sign);

    gsl_matrix *U = gsl_matrix_alloc(3,3);
    gsl_matrix *L = gsl_matrix_alloc(3,3);

    printf("U = \n");

    for (i=0;i<3;i=i+1)
    {
      for (j = 0;j<3;j=j+1)
      {
        if(j<i)
          {printf("0.00\t\t");gsl_matrix_set(U,i,j,0);}
        else
        {printf("%0.2f\t\t",gsl_matrix_get(M,i,j));gsl_matrix_set(U,i,j,gsl_matrix_get(M,i,j));}
      }
      printf("\n");
    }
    printf("\n");


    printf("L = \n");

    for(i=0;i<3;i=i+1)
    {
      for(j=0;j<3;j=j+1)
      {
        if(j>i)
          {printf("0.00\t\t");gsl_matrix_set(L,i,j,0);}
        else
        {
          if(j == i)
            {printf("1.00\t\t");gsl_matrix_set(L,i,j,1);}
          else
            {printf("%0.2f\t\t",gsl_matrix_get(M,i,j));gsl_matrix_set(L,i,j,gsl_matrix_get(M,i,j));}
        }
      }
      printf("\n");
    }
    printf("\n");


    gsl_matrix *P = gsl_matrix_alloc(3,3);
    gsl_matrix *Identity = gsl_matrix_alloc(3,3);
    gsl_matrix_set_identity(Identity);

    printf("P = \n");

    for(i=0;i<3;i=i+1)
    {
      for(j=0;j<3;j=j+1)
      {
        gsl_matrix_set(P,i,j,gsl_matrix_get(Identity,i,gsl_permutation_get(p,j)));
        printf("%0.2f\t\t",gsl_matrix_get(P,i,j));
      }
      printf("\n");
    }


    double Sum1 = 0;
    double Sum2 = 0;

    for(i = 0;i<3;i=i+1)
    {
      for(j=0;j<3;j=j+1)
      {
        for(k=0;k<3;k=k+1)
        {
          Sum1 = Sum1 + gsl_matrix_get(P,i,k)*gsl_matrix_get(A,k,j);
          Sum2 = Sum2 + gsl_matrix_get(L,i,k)*gsl_matrix_get(U,k,j);
        }
        if(Sum1 != Sum2)
          flag = 1;
        Sum1 = 0;
        Sum2 = 0;
      }
    }

    if(flag == 1)
      printf("PA is not equal to LU\n");
    else
      printf("PA is equal to LU\n");


    gsl_permutation_free(p);
    gsl_matrix_free(M);
    gsl_matrix_free(U);
    gsl_matrix_free(L);
    gsl_matrix_free(P);
    gsl_matrix_free(Identity);
    return 0;
}
