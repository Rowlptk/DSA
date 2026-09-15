#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void queue_operations();
void enqueue();
void show_queue();
void dequeue();

int main()
{
    queue_operations();
    return 0;
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQUEUE is Empty!\n");
        return;
    }
    
    printf("\nElement Removed : %d\n", queue[front]);
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1)%MAX_SIZE;
    }
}

void show_queue()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is empty!\n");
        return;
    }
    
    int count = (rear + MAX_SIZE - front)%MAX_SIZE + 1;
    printf("\nQUEUE ELEMENTS : ");
    for(int i = 0; i < count; i++)
    {
        int index = (front + i)%MAX_SIZE;
        printf("%d ", queue[index]);
    }
    printf("\n");
}

void enqueue()
{
    int num;
    
    if((rear + 1)%MAX_SIZE == front) 
    {
        printf("\nQueue is Full!\n");
        return;
    }
    
    printf("\nEnter number to enqueue : ");
    scanf("%d", &num);
    
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear+1)%MAX_SIZE;
    }
    queue[rear] = num;
    
    printf("\n%d added to queue.\n", num);
}

void queue_operations()
{
    int choice;
    printf("BASIC OPERATIONS OF QUEUE : \n");
    printf("----------------------------\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Show Queue\n");
    printf("4. Exit\n");
    printf("   Choice : ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            show_queue();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Choice!\n");
    }
    
    printf("\nPress any key to continue...  ");
    getchar();
    getchar();
    
    queue_operations();
}
