#include<stdio.h>
#include<stdlib.h>

struct node {
    int vertex;
    struct node *next;
};

struct graph {
    int num_of_vertices;
    int *visited;
    
    struct node **adj_lists;
};

struct node* create_node(int n);
struct graph* create_graph(int vertices);
void add_edge(struct graph* g, int s, int d);
void print_graph(struct graph* g);
void DFS(struct graph *g, int vertex);

int main()
{
    int n,s,d;
    printf("***********DFS************\n");
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    struct graph* new_graph = create_graph(n);
    
    printf("\nAdd Edges: ");
    printf("\nEnter number of edges : ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("\nEdge %d :\n", i+1);
        printf("Source Vertex : ");
        scanf("%d", &s);
        printf("Destination Vertex : ");
        scanf("%d", &d);
        add_edge(new_graph, s, d);
    }
    //add_edge(new_graph, 0, 1);
    //add_edge(new_graph, 0, 2);
    //add_edge(new_graph, 1, 2);
    //add_edge(new_graph, 2, 3);
    
    print_graph(new_graph);
    
    printf("\nEnter the start vertex for DFS: ");
    scanf("%d", &n);
    printf("\nDFS visited PATH : \n");
    DFS(new_graph, n);
    
    return 0;
}

void DFS(struct graph *g, int vertex)
{
    struct node *adj_list = g->adj_lists[vertex];
    struct node *temp = adj_list;
    
    g->visited[vertex] = 1;
    printf("Visited : %d \n", vertex);
    
    while(temp != NULL)
    {
        int con_vertex = temp->vertex;
        
        if(g->visited[con_vertex] == 0)
        {
            DFS(g, con_vertex);
        }
        temp = temp->next;
    }
}

void print_graph(struct graph* g)
{
    for(int i=0; i<g->num_of_vertices; i++)
    {
        struct node* temp = g->adj_lists[i];
        printf("\nAdjacency list : vertex %d\n", i);
        while(temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void add_edge(struct graph* g, int s, int d)
{
    struct node* new_node = create_node(d);

    new_node->next = g->adj_lists[s];
    g->adj_lists[s] = new_node;
    
    new_node = create_node(s);
    new_node->next = g->adj_lists[d];
    g->adj_lists[d] = new_node;
}

struct graph* create_graph(int vertices)
{
    struct graph *new_graph = malloc(sizeof(struct graph));
    
    new_graph->num_of_vertices = vertices;
    new_graph->adj_lists = malloc(vertices * sizeof(struct node*));
    new_graph->visited = malloc(vertices * sizeof(int));
    
    for(int i=0; i<vertices; i++)
    {
        new_graph->adj_lists[i] = NULL;
        new_graph->visited[i] = 0;
    }
    return new_graph;
}

struct node* create_node(int n) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->vertex = n;
    new_node->next = NULL;
    return new_node;
}