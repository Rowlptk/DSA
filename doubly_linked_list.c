#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
int n;

void add_node_front();
void traverse_forward();
void operations();
void traverse_backward();
void add_node_position();
void add_node_end();
void delete_node_front();
void delete_node_position();
void delete_node_end();

int main()
{
    printf("CREATE A DOUBLY LINKED LIST: \n\n");
    printf("How many node to insert : ");
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++)
    {
        printf("Creating %d node : ", i);
        add_node_front();
    }
    
    printf("\nDoubly Linked List Created of %d nodes!\n", n);
    
    operations();
    // traverse_forward();
    
    return 0;
}

void operations()
{
    int choice;
    printf("BASIC OPERATIONS ON DOUBLY LINKED LIST : \n");
    printf("---------------------------------------------\n");
    printf("1. TRAVERSE FORWARD\n");
    printf("2. TRAVERSE BACKWARD\n");
    printf("3. INSERT AT FRONT\n");
    printf("4. INSERT AT POSITION\n");
    printf("5. INSERT AT END\n");
    printf("6. DELETE AT FRONT\n");
    printf("7. DELETE AT POSITION\n");
    printf("8. DELETE AT END\n");
    printf("9. EXIT\n");
    printf("CHOICE : ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            traverse_forward();
            break;
        case 2:
            traverse_backward();
            break;
        case 3:
            add_node_front();
            printf("\nNode inserted at the front!\n");
            n++;
            break;
        case 4:
            add_node_position();
            break;
        case 5:
            add_node_end();
            break;
        case 6:
            delete_node_front();
            break;
        case 7:
            delete_node_position();
            break;
        case 8:
            delete_node_end();
            break;
        case 9:
            exit(0);
        default:
            printf("\nInvalid Option!\n");
    }
    
    if(choice<9)
    {
        printf("\nTotal Number of Nodes in Doubly Linked List: %d\n", n);
    }
    
    printf("\nPress any key to continue ... ");
    getchar();
    getchar();
    
    operations();
}

void delete_node_end()
{
    struct Node *temp;
    if(head == NULL)
    {
        printf("\nList is Empty!");
    }
    else if(head->next == NULL)
    {
        head = NULL;
        printf("\nRemoved data is %d\n", head->data);
        free(head);
        n--;
        printf("\nData deleted at the end!\n");
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->prev->next = NULL;
        printf("\nRemoved data is %d\n", temp->data);
        free(temp);
        n--;
        printf("\nData deleted at the end!\n");
    }
}

void delete_node_position()
{
    struct Node *temp;
    int pos;
    
    if(head == NULL)
    {
        printf("\nList is Empty!\n");
    }
    else
    {   
        do
        {
            printf("\nEnter Position [1-%d] : ", n);
            scanf("%d", &pos);
        }while(pos>n);
        
        temp = head;
        
        if(pos == 1)
        {
            head = head->next;
            head->prev = NULL;
            printf("\nRemoved data is %d\n", temp->data);
            free(temp);
            n--;
            printf("\nNode deleted at position : %d\n", pos);
        }
        else
        {
            for(int i = 1; i<pos; i++)
            {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            printf("\nRemoved data is %d\n", temp->data);
            free(temp);
            n--;
            printf("\nNode deleted at position : %d\n", pos);
        }
    }
}

void delete_node_front()
{
    struct Node *temp;
    if(head == NULL)
    {
        printf("\nList is Empty!\n");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        printf("\nRemoved data is %d\n", temp->data);
        free(temp);
        n--;
        printf("\nNode deleted at the front!\n");
    }
}

void add_node_end()
{
    struct Node *new_node, *temp;
    int data;
    
    new_node = malloc(sizeof(struct Node));
    
    printf("\nEnter Data : ");
    scanf("%d", &data);
    
    new_node->data = data;
    new_node->next = NULL;
    
    if(head == NULL)
    {
        new_node->prev = NULL;
        head = new_node;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    n++;
    printf("\nNode Inserted at the end!\n");
}

void add_node_position()
{
    struct Node *new_node, *temp;
    int data, pos;
    
    new_node = malloc(sizeof(struct Node));
    
    do{
        printf("\nEnter position [1-%d] : ", n);
        scanf("%d", &pos);
    }while(pos>n);
    
    printf("\nEnter data : ");
    scanf("%d", &data);
    
    new_node->data = data;
    
    if(pos == 1)
    {
        new_node->next = head;
        new_node->prev = NULL;
        if(head != NULL)
        {
            head->prev = new_node;
        }
        head = new_node;
        
        printf("\nNode inserted at position : %d\n", pos);
        n++;
    }
    else
    {
        temp = head;
        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }
    
        new_node->next = temp->next;
        new_node->prev = temp;
    
        if(temp->next != NULL)
        {
            temp->next->prev = new_node;
        }
        temp->next = new_node;
    
        printf("\nNode inserted at position : %d\n", pos);
        n++;
    }
}

void traverse_backward()
{
    struct Node *temp = head;
    int i = 1;
    if(head == NULL)
    {
        printf("\nList is Empty!\n");
    }
    else
    {
        printf("\nDoubly Linked List(backward) : \n");
        while(temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        
        printf("Data %d = %d\n", i, temp->data);
        while(temp != head)
        {
            temp = temp->prev;
            i--;
            printf("Data %d = %d\n", i, temp->data);
        }
    }
}

void traverse_forward()
{
    struct Node *temp = head;
    int i = 1;
    if(head == NULL)
    {
        printf("\nList is Empty!\n");
    }
    else
    {
        printf("\nDoubly Linked List(forward) : \n");
        while(temp != NULL)
        {
            printf("Data %d = %d\n", i, temp->data);
            temp = temp->next;
            i++;
        }
    }
}

void add_node_front()
{
    struct Node *new_node;
    int data;
    new_node = malloc(sizeof(struct Node));
    
    printf("\nEnter data : ");
    scanf("%d", &data);
    
    new_node->data = data;
    
    new_node->next = head;
    new_node->prev = NULL;
    
    if(head != NULL)
    {
        head->prev = new_node;
    }
     head = new_node;
}
