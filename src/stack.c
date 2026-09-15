#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int x);
void pop();
void top_of_stack();
int is_empty();
void show();


int main()
{
    int choice, x;
    printf("BASIC STACK OPERATIONS : ");
    printf("\n---------------------------\n");
    printf("1. PUSH\n2. POP\n3. Element at Top\n4. is Empty?\n5. Show\n6. Exit\n");
    do {
        printf("Choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter number to push : ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                top_of_stack();
                break;
            case 4:
                if(is_empty())
                    printf("\nStack is Empty!\n");
                else
                    printf("\nStack is not Empty!\n");
                break;
            case 5:
                show();
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid Choice!\n");
        }
    }while(choice!=6);
    
    return 0;
}

void push(int x)
{
    if(top == MAX_SIZE - 1)
    {
        printf("\nError: Stack OVERFLOW!\n");
    }
    else 
    {
        // top++
        // stack[top] = x;
        stack[++top] = x;
        printf("Element Pushed to Stack : %d\n", x);
    }
}

void pop()
{
    if(top == -1)
    {
        printf("\nError: Stack UNDERFLOW!\n");
    }
    else
    {
        printf("Popped Element = %d\n", stack[top]);
        top--;
    }
}

void top_of_stack()
{
    if(!is_empty())
        printf("\nElement at Top of Stack: %d\n", stack[top]);
    else
        printf("\nStack is Empty!\n");
}


int is_empty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void show()
{
    if(!is_empty())
    {
        printf("Stack Values are: \n");
        for(int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nStack is Empty!\n");
    }
}