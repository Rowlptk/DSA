#include<stdio.h>

int main()
{
    int n, i, j, adj_matrix[10][10], indeg[10], flag[10], count = 0;
    printf("Enter no of vertices : ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Row %d column %d = ", i+1, j+1);
            scanf("%d", &adj_matrix[i][j]);
        }
    }
    
    for(i=0; i<n; i++)
    {
        indeg[i] = 0;
        flag[i] = 0;
    }
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<n ; j++)
        {
            indeg[i] = indeg[i] + adj_matrix[j][i];
        }
    }
    
    printf("\nTopological Order : ");
    
    while(count < n)
    {
        for(i=0; i<n; i++)
        {
            if((indeg[i]==0) && (flag[i]==0))
            {
                printf("%d ", i+1);
                flag[i] = 1;
            }
            
            for(j=0; j<n; j++)
            {
                if(adj_matrix[j][i] == 1)
                {
                    indeg[i]--;
                }
            }
        }
        count++;
    }
    return 0;
}