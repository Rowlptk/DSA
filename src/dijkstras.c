#include<stdio.h>
#define INFINITY 9999

void dijkstra(int g[10][10], int n, int start);

int main()
{
    int n, s, graph[10][10];
    /*
    printf("Enter no of nodes : ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix value: \n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("\n\nEnter the start node : ");
    scanf("%d", &s);
    */
    n = 7;

    graph[0][0] = 0;
    graph[0][1] = 0;
    graph[0][2] = 1;
    graph[0][3] = 2;
    graph[0][4] = 0;
    graph[0][5] = 0;
    graph[0][6] = 0;

    graph[1][0] = 0;
    graph[1][1] = 0;
    graph[1][2] = 2;
    graph[1][3] = 0;
    graph[1][4] = 0;
    graph[1][5] = 3;
    graph[1][6] = 0;

    graph[2][0] = 1;
    graph[2][1] = 2;
    graph[2][2] = 0;
    graph[2][3] = 1;
    graph[2][4] = 3;
    graph[2][5] = 0;
    graph[2][6] = 0;

    graph[3][0] = 2;
    graph[3][1] = 0;
    graph[3][2] = 1;
    graph[3][3] = 0;
    graph[3][4] = 0;
    graph[3][5] = 0;
    graph[3][6] = 1;

    graph[4][0] = 0;
    graph[4][1] = 0;
    graph[4][2] = 3;
    graph[4][3] = 0;
    graph[4][4] = 0;
    graph[4][5] = 2;
    graph[4][6] = 0;

    graph[5][0] = 0;
    graph[5][1] = 3;
    graph[5][2] = 0;
    graph[5][3] = 0;
    graph[5][4] = 2;
    graph[5][5] = 0;
    graph[5][6] = 1;

    graph[6][0] = 0;
    graph[6][1] = 0;
    graph[6][2] = 0;
    graph[6][3] = 1;
    graph[6][4] = 0;
    graph[6][5] = 1;
    graph[6][6] = 0;

    s = 0;
    
    dijkstra(graph, n, s);
    
    return 0;
}

void dijkstra(int g[10][10], int n, int start)
{
    int cost[10][10], dist[10], pred[10], visited[10];
    int count, min_dist, next_node;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(g[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = g[i][j];
            }
        }
    }
    
    for(int i=0; i<n; i++)
    {
        dist[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
    
    dist[start] = 0;
    visited[start] = 1;
    count = 1;
    
    while(count < n-1)
    {
        min_dist = INFINITY;
        
        for(int i=0; i<n; i++)
        {
            if(dist[i] < min_dist && !visited[i]) 
            {
                min_dist = dist[i];
                next_node = i;
            }
        }
        
        visited[next_node] = 1;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                if(min_dist + cost[next_node][i] < dist[i])
                {
                    dist[i] = min_dist + cost[next_node][i];
                    pred[i] = next_node;
                }
            }
        }
        count++;
    }
    
    for(int i=0; i<n; i++)
    {
        if(i != start)
        {
            printf("\nDistance to %d : %d", i, dist[i]);
        }
    }
}