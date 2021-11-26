#include<stdio.h>
#include<stdlib.h>

#define SIZE 40

struct queue {
    int items[SIZE];
    int front;
    int rear;
};

struct node {
    int vertex;
    struct node *next;
};

struct graph {
    int num_of_vertices;
    int *visited;
    struct node **adj_lists;
};

struct graph* create_graph(int vertices);
struct node* create_node(int n);
void add_edge(struct graph *g, int s, int d);
struct queue* create_queue();
void enqueue(struct queue *q, int value);
int is_empty(struct queue *q);
void print_queue(struct queue *q);
int dequeue(struct queue *q);
void BFS(struct graph *g, int vertex);

int main()
{
    int n,s,d;
    printf("***********BFS************\n");
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
    
    printf("\nEnter the start vertex for DFS: ");
    scanf("%d", &n);
    printf("\nBFS visited PATH : \n");
    BFS(new_graph, n);
    /*add_edge(new_graph, 0, 1);
    add_edge(new_graph, 0, 2);
    add_edge(new_graph, 1, 2);
    add_edge(new_graph, 1, 4);
    add_edge(new_graph, 1, 3);
    add_edge(new_graph, 2, 4);
    add_edge(new_graph, 3, 4);
    */
    
    return 0;
}

void BFS(struct graph *g, int vertex)
{
    struct queue *q = create_queue();
    
    g->visited[vertex] = 1;
    enqueue(q, vertex);
    
    while(!is_empty(q))
    {
        print_queue(q);
        int cur_vertex = dequeue(q);
        printf("\nVisited %d\n", cur_vertex);
        
        struct node *temp = g->adj_lists[cur_vertex];
        
        while(temp)
        {
            int adj_vertex = temp->vertex;
            
            if(g->visited[adj_vertex] == 0)
            {
                g->visited[adj_vertex] = 1;
                enqueue(q, adj_vertex);
            }
            temp = temp->next;
        }
    }
}

int dequeue(struct queue *q)
{
    int item;
    if(is_empty(q))
    {
        printf("\nQueue is Empty!\n");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
    }
    return item;
}

void print_queue(struct queue *q)
{
    if(is_empty(q))
    {
        printf("\nQueue is Empty!");
    }
    else
    {
        printf("\nQueue contains : ");
        for(int i = q->front; i<q->rear + 1; i++)
        {
            printf("%d ", q->items[i]);
        }
    }
}

int is_empty(struct queue *q)
{
    if(q->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int value)
{
    if(q->rear == SIZE-1)
    {
        printf("\nQueue is Full!\n");
    }
    else
    {
        if(q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

struct queue* create_queue()
{
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void add_edge(struct graph *g, int s, int d)
{
    struct node *new_node = create_node(d);
    new_node->next = g->adj_lists[s];
    g->adj_lists[s] = new_node;
    
    new_node = create_node(s);
    new_node->next = g->adj_lists[d];
    g->adj_lists[d] = new_node;
}

struct node* create_node(int n)
{
    struct node* new_node = malloc(sizeof(struct node));
    new_node->vertex = n;
    new_node->next = NULL;
    return new_node;
}

struct graph* create_graph(int vertices)
{
    struct graph *g = malloc(sizeof(struct graph));
    g->num_of_vertices = vertices;
    
    g->adj_lists = malloc(vertices * sizeof(struct node));
    g->visited = malloc(vertices * sizeof(int));
    
    for(int i=0; i<vertices; i++)
    {
        g->adj_lists[i] = NULL;
        g->visited[i] = 0;
    }
    
    return g;
}