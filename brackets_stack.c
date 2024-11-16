#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
int top = -1;
char stack_arr[max];
int isfull()
{
    if (top == max - 1)
        return 1;
    else
        return 0;
}
int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push(char data)
{
    if (isfull())
    {
        //(top==max-1)
        printf(" stack overflow");
        exit(1);
    }
    top = top + 1;
    stack_arr[top] = data;
}
char pop()
{
    if (isempty())
    {
        //(top==-1)
        printf("under flow");
        exit(1);
    }
    char value = stack_arr[top];
    top = top - 1;
    return value;
}
int match(char a, char b)
{
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    return 0;
}
int check(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (isempty())
            {
                printf("more right brackets\n");
                return 0;
            }
            else
            {
                char temp = pop();
                if (!match(temp, s[i]))
                {
                    printf("not matched\n");
                    return 0;
                }
            }
        }
    }
    if (isempty())
    {
        printf("balenced\n");
        return 1;
    }
    else
    {
        printf("more left brackets\n");
        return 0;
    }
}
int main()
{
    char arr[max];
    printf("enter expression \n");
    scanf("%s", &arr);
    int a;
    a = check(arr);
    if (a == 1)
    {
        printf("valid expression\n");
    }
    else
    {
        printf("invalid expression\n");
    }
    return 0;
}