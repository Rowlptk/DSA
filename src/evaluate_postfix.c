#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>


#define SIZE 50

int stack[SIZE];
int top = -1;

void evaluate_postfix(char postfix[]);
void push(int num);
int pop();

int main()
{
    char postfix[SIZE];
    printf("Enter Postfix Expression: ");
    gets(postfix);
    // scanf(" %s", postfix);
    
    evaluate_postfix(postfix);
    
    return 0;
}

void evaluate_postfix(char postfix[])
{
    int i, num1, num2, res;
    char ch;
    
    i = 0;
    ch = postfix[i];
    
    while(ch != '\0')
    {
        if(isdigit(ch))
        {
            push(ch - '0');
        }
        else if(ch=='/'||ch=='*'||ch=='+'||ch=='-'||ch=='^')
        {
            num2 = pop();
            num1 = pop();
            
            switch(ch)
            {
                case '/':
                    res = num1 / num2;
                    break;
                case '*':
                    res = num1 * num2;
                    break;
                case '+':
                    res = num1 + num2;
                    break;
                case '-':
                    res = num1 - num2;
                    break;
                case '^':
                    res = 1;
                    for(int j=1; j<=num2; j++)
                    {
                        res *= num1;
                    }
                    break;
            }
            
            push(res);
        }
        else
        {
            printf("\nInvalid Expression!");
            getchar();
            exit(0);
        }
        
        i++;
        ch = postfix[i];
    }
    printf("Result of Postfix Expression : %d\n", pop());
}

void push(int num)
{
    if(top == SIZE - 1)
    {
        printf("\nError: Stack OVERFLOW!");
        getchar();
        exit(0);
    }
    stack[++top] = num;
}

int pop()
{
    if(top == -1)
    {
        printf("\nError: Stack UNDERFLOW!");
        getchar();
        exit(0);
    }
    top--;
    return stack[top+1];
}