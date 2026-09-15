#include <stdio.h>
#include <stdlib.h>

#define INF 99999

struct edge {
  int u;
  int v;
  int w;
};

struct graph {
  int V;   
  int E;   
  struct edge *e; 
};

void bellman_ford(struct graph *g, int source);
void display(int arr[], int size);

int main() 
{
  struct graph *g = (struct graph *)malloc(sizeof(struct graph));
  g->V = 4; 
  g->E = 5; 

  g->e = (struct edge *)malloc(g->E * sizeof(struct edge));

  g->e[0].u = 0;
  g->e[0].v = 1;
  g->e[0].w = 5;

  g->e[1].u = 0;
  g->e[1].v = 2;
  g->e[1].w = 4;

  g->e[2].u = 1;
  g->e[2].v = 3;
  g->e[2].w = 3;

  g->e[3].u = 2;
  g->e[3].v = 1;
  g->e[3].w = 6;

  g->e[4].u = 3;
  g->e[4].v = 2;
  g->e[4].w = 2;

  bellman_ford(g, 0);  

  return 0;
}

void bellman_ford(struct graph *g, int source) 
{
  int i, j, u, v, w;

  int tV = g->V;

  int tE = g->E;

  int d[tV];

  int p[tV];

  for (i = 0; i < tV; i++) 
  {
    d[i] = INF;
    p[i] = 0;
  }

  d[source] = 0;

  for (i = 1; i <= tV - 1; i++) 
  {
    for (j = 0; j < tE; j++) 
    {
      u = g->e[j].u;
      v = g->e[j].v;
      w = g->e[j].w;

      if (d[u] != INF && d[v] > d[u] + w) 
      {
        d[v] = d[u] + w;
        p[v] = u;
      }
    }
  }

  for (i = 0; i < tE; i++) 
  {
    u = g->e[i].u;
    v = g->e[i].v;
    w = g->e[i].w;
    if (d[u] != INF && d[v] > d[u] + w) 
    {
      printf("Negative weight cycle detected!\n");
      return;
    }
  }

  printf("Distance array: ");
  display(d, tV);
  printf("Predecessor array: ");
  display(p, tV);
}

void display(int arr[], int size) 
{
  int i;
  for (i = 0; i < size; i++) 
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}