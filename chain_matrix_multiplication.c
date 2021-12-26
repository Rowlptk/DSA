#include<stdio.h>
#include<limits.h>

int matrix_chain_mult(int a[], int n);

int main()
{
    int n, i;
    printf("Enter no. of Matrices : ");
    scanf("%d", &n);
    
    int a[n];
    
    printf("enter dimensions of %d matrices : ", n);
    for(i=0; i<n; i++)
    {
        printf("\ndimension %d : ", i);
        scanf("%d", &a[i]);
    }
    
    int size = sizeof(a)/sizeof(a[0]);
    
    printf("\nMinimum no of multiplications = %d", matrix_chain_mult(a, size));

    return 0;
}

int matrix_chain_mult(int a[], int n)
{
    int m[n][n];
    int i, j, k, l, q;
    
    for(i=1; i<n; i++)
    {
        m[i][i] = 0;
    }
    
    for(l=2; l<n; l++)
    {
        for(i=1; i<n-l+1; i++)
        {
            j = i+l-1;
            m[i][j] = INT_MAX;
            
            for(k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + a[i-1]*a[k]*a[j];
                if(q<m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n-1];
}