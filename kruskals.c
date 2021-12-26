#include <stdio.h>

#define MAX 30

struct edge {
  int u, v, w;
};

struct edge_list {
  struct edge data[MAX];
  int n;
};

struct edge_list elist;

int g[MAX][MAX], n;
struct edge_list spanlist;

void kruskal_algo();
int find(int belongs[], int vertexno);
void apply_union(int belongs[], int c1, int c2);
void sort();
void print();

int main() 
{
  int i, j, total_cost;

  n = 6;

  g[0][0] = 0;
  g[0][1] = 4;
  g[0][2] = 4;
  g[0][3] = 0;
  g[0][4] = 0;
  g[0][5] = 0;
  g[0][6] = 0;

  g[1][0] = 4;
  g[1][1] = 0;
  g[1][2] = 2;
  g[1][3] = 0;
  g[1][4] = 0;
  g[1][5] = 0;
  g[1][6] = 0;

  g[2][0] = 4;
  g[2][1] = 2;
  g[2][2] = 0;
  g[2][3] = 3;
  g[2][4] = 4;
  g[2][5] = 0;
  g[2][6] = 0;

  g[3][0] = 0;
  g[3][1] = 0;
  g[3][2] = 3;
  g[3][3] = 0;
  g[3][4] = 3;
  g[3][5] = 0;
  g[3][6] = 0;

  g[4][0] = 0;
  g[4][1] = 0;
  g[4][2] = 4;
  g[4][3] = 3;
  g[4][4] = 0;
  g[4][5] = 0;
  g[4][6] = 0;

  g[5][0] = 0;
  g[5][1] = 0;
  g[5][2] = 2;
  g[5][3] = 0;
  g[5][4] = 3;
  g[5][5] = 0;
  g[5][6] = 0;

  kruskal_algo();
  print();
}

void kruskal_algo() 
{
  int belongs[MAX], i, j, cno1, cno2;
  elist.n = 0;

  for (i = 1; i < n; i++)
  {
    for (j = 0; j < i; j++) 
    {
      if (g[i][j] != 0) 
      {
        elist.data[elist.n].u = i;
        elist.data[elist.n].v = j;
        elist.data[elist.n].w = g[i][j];
        elist.n++;
      }
    }
  }

  sort();

  for (i = 0; i < n; i++)
  {
    belongs[i] = i;
  }
  
  spanlist.n = 0;

  for (i = 0; i < elist.n; i++) 
  {
    cno1 = find(belongs, elist.data[i].u);
    cno2 = find(belongs, elist.data[i].v);

    if (cno1 != cno2) 
    {
      spanlist.data[spanlist.n] = elist.data[i];
      spanlist.n = spanlist.n + 1;
      apply_union(belongs, cno1, cno2);
    }
  }
}

int find(int belongs[], int vertexno)
{
  return (belongs[vertexno]);
}

void apply_union(int belongs[], int c1, int c2) 
{
  int i;

  for (i = 0; i < n; i++)
  {
    if (belongs[i] == c2)
    {
      belongs[i] = c1;
    }
  }
}

void sort() 
{
  int i, j;
  struct edge temp;

  for (i = 1; i < elist.n; i++)
  {
    for (j = 0; j < elist.n - 1; j++)
    {
      if (elist.data[j].w > elist.data[j + 1].w) 
      {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
    }
  }
}

void print() 
{
  int i, cost = 0;

  for (i = 0; i < spanlist.n; i++) 
  {
    printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
    cost = cost + spanlist.data[i].w;
  }

  printf("\nSpanning tree cost: %d", cost);
}