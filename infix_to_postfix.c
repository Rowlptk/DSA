#include<stdio.h>
#include<ctype.h> // for isalpha() and isdigit()
#include<string.h>
#include<stdlib.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char ch);
int is_operator(char op);
char pop();
int precedence(char op);
void infix_to_postfix(char infix[], char postfix[]);

int main()
{
    char infix[SIZE], postfix[SIZE];
    printf("Infix Expression to Postfix Expression\nusing Stack Operations: ");
    printf("\n------------------------------------------------------\n");
    
    printf("Enter Infix Expression : ");
    gets(infix);
   
    infix_to_postfix(infix, postfix);
    printf("Postfix Expression : ");
    puts(postfix);
   
    return 0;
}

void infix_to_postfix(char infix[], char postfix[])
{
    char ch, x;
    int i, j;
    
    push('(');
    strcat(infix, ")");
    
    i = 0;
    j = 0;
    
    ch = infix[i];
    
    while(ch != '\0')
    {
        if(ch == '(')
        {
            push(ch);
        }
        else if(isdigit(ch) || isalpha(ch))
        {
            postfix[j] = ch;
            j++;
        }
        else if(is_operator(ch) == 1)
        {
            x = pop();
            while(is_operator(x) == 1 && precedence(x) >= precedence(ch))
            {
                postfix[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(ch);
        }
        else if(ch == ')')
        {
            x = pop();
            while(x != '(')
            {
                postfix[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {
            printf("\nInvalid Infix Expression!");
            getchar();
            exit(0);
        }
        
        i++;
        
        ch = infix[i];
    }
    
    postfix[j] = '\0';
    
}

int precedence(char op)
{
    if(op == '^')
    {
        return 3;
    }
    else if(op == '*' || op =='/')
    {
        return 2;
    }
    else if(op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char pop()
{
    char ch;
    if(top == -1)
    {
        printf("\nError: Stack UNDERFLOW!");
        getchar();
        exit(0);
    }
    else
    {
        ch = stack[top];
        top--;
        return(ch);
    }
}

int is_operator(char op)
{
    if(op == '^' || op == '/' || op == '*' || op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char ch)
{
    if(top == SIZE - 1)
    {
        printf("\nError: Stack OVERFLOW!");
        getchar();
        exit(0);
    }
    else
    {
        stack[++top] = ch;
    }
}

