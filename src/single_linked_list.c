#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node * head = NULL;
int n;

void insert_at_front();
void traverse();
void operations();
void insert_at_end();
void insert_at_position();
void delete_at_front();
void delete_at_end();
void delete_at_position();

int main()
{
    printf("CREATE A LINKED LIST: \n\n");
    printf("How many items to insert: ");
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++)
    {
        printf("Creating %d item : ", i);
        insert_at_front();
    }
    
    printf("\nLinked List Created of %d items!\n", n);
    
    
    operations();
    // traverse();
    
    return 0;
}

void operations()
{
    int choice;
    printf("BASIC OPERATIONS ON LINKED LIST : \n");
    printf("---------------------------------------\n");
    printf("1. TRAVERSE\n");
    printf("2. INSERT AT FRONT\n");
    printf("3. INSERT AT POSITION\n");
    printf("4. INSERT AT END\n");
    printf("5. DELETE AT FRONT\n");
    printf("6. DELETE AT POSITION\n");
    printf("7. DELETE AT END\n");
    printf("8. EXIT\n");
    printf("CHOICE : ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            traverse();
            break;
        case 2:
            insert_at_front();
            printf("\nData inserted at the front!\n");
            n++;
            break;
        case 3:
            insert_at_position();
            break;
        case 4:
            insert_at_end();
            break;
        case 5:
            delete_at_front();
            break;
        case 6:
            delete_at_position();
            break;
        case 7:
            delete_at_end();
            break;
        case 8:
            exit(0);
        default:
            printf("\nInvalid Option!\n");
    }
    
    if(choice<8)
    {
        printf("\nTotal Number of Items in Linked List: %d\n", n);
    }
    
    printf("\nPress any key to continue ...  ");
    getchar();
    getchar();
    
    operations();
}

void delete_at_position()
{
    struct Node *temp, *del_node;
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
        } while(pos>n);
        
        temp = head;
        
        if(pos == 1)
        {
            head = temp->next;
            printf("\nRemoved data is %d\n", temp->data);
            free(temp);
            n--;
            printf("\nItem deleted at position : %d\n", pos);

        }
        else
        {
            for(int i=0; i<pos-2; i++)
            {
                temp = temp->next;
            }
        
            del_node = temp->next;
            temp->next = del_node->next;
            printf("\nRemoved data is %d\n", del_node->data);
            free(del_node);
            n--;
            printf("\nItem deleted at position : %d\n", pos);
        }
    }
    
}

void delete_at_end()
{
    struct Node *temp, *prev_node;
    if(head == NULL)
    {
        printf("\nList is Empty!\n");
    }
    else
    {
        temp = head;
        while(temp->next != 0)
        {
            prev_node = temp;
            temp = temp->next;
        }
        printf("\nRemoved data is %d\n", temp->data);
        free(temp);
        prev_node->next = NULL;
        n--;
        printf("\nData deleted at the end!\n");

    }
}

void delete_at_front()
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
        printf("\nRemoved data is %d\n", temp->data);
        free(temp);
        n--;            
        printf("\nData deleted at the front!\n");
    }
}

void insert_at_position()
{
    struct Node *new_node, *temp;
    int pos, data;
    
    new_node = malloc(sizeof(struct Node));
    
    do
    {
        printf("\nEnter Position [1-%d] : ", n);
        scanf("%d", &pos);
    } while(pos>n);
    
    printf("\nEnter Data : ");
    scanf("%d", &data);
    
    new_node->data = data;
    new_node->next = NULL;
    
    if(pos == 1)
    {
        new_node->next = head;
        head = new_node;
        
        printf("\nItem Inserted at position : %d\n", pos);
        n++;
    }
    else
    {
        temp = head;
        for(int i=0; i<pos-2; i++)
        {
            temp = temp->next;
        }
    
        new_node->next = temp->next;
        temp->next = new_node;
    
        printf("\nItem Inserted at position : %d\n", pos);
        n++;
    }
}

void insert_at_end()
{
    struct Node *new_node, *temp;
    int data;
    
    new_node = malloc(sizeof(struct Node));
    
    printf("Enter Data : ");
    scanf("%d", &data);
    
    new_node->data = data;
    new_node->next = NULL;
    
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = new_node;
    n++;
    printf("\nData inserted at the end!\n");
}

void traverse()
{
    struct Node *temp = head;
    int i = 1;
    if(head == NULL)
    {
        printf("\nList is Empty!");
    }
    else
    {
        printf("\n");
        while(temp != NULL)
        {
            printf("Data %d = %d\n", i, temp->data);
            temp = temp->next;
            i++;
        }
    }
}

void insert_at_front()
{
    struct Node *new_node;
    int data;
    
    new_node = malloc(sizeof(struct Node));
    
    printf("\nEnter data : ");
    scanf("%d", &data);
    
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}