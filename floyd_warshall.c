#include <stdio.h>

#define nV 4

#define INF 999

void print_matrix(int m[][nV]);
void floyd_warshall(int g[][nV]);
void print_matrix(int m[][nV]);

int main() 
{
  int g[nV][nV] = {{0, 3, INF, 5},
             {2, 0, INF, 4},
             {INF, 1, 0, INF},
             {INF, INF, 2, 0}};
  floyd_warshall(g);
  return 0;
}

void floyd_warshall(int g[][nV]) 
{
  int m[nV][nV], i, j, k;

  for (i = 0; i < nV; i++)
  {
    for (j = 0; j < nV; j++)
    {
      m[i][j] = g[i][j];
    }
  }

  for (k = 0; k < nV; k++) 
  {
    for (i = 0; i < nV; i++) 
    {
      for (j = 0; j < nV; j++) 
      {
        if (m[i][k] + m[k][j] < m[i][j])
          m[i][j] = m[i][k] + m[k][j];
      }
    }
  }
  print_matrix(m);
}

void print_matrix(int m[][nV]) 
{
  for (int i = 0; i < nV; i++) 
  {
    for (int j = 0; j < nV; j++) 
    {
      if (m[i][j] == INF)
      {
        printf("%4s", "INF");
      }
      else
      {
        printf("%4d", m[i][j]);
      }
    }
    printf("\n");
  }
}