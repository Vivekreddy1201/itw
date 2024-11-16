// to print prime factors of a number in desending order
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define max 10
int top = -1;
int stack_arr[max];
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
void push(int data)
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
int pop()
{
    if (isempty())
    {
        //(top==-1)
        printf("under flow");
        exit(1);
    }
    int value = stack_arr[top];
    top = top - 1;
    return value;
}
void print()
{
    if (isempty())
    {
        // top<0
        printf("under flow");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack_arr[i]);
    }
}
int main()
{
    int n = 450;
    int i = 2;
    while (n != 1)
    {
        while (n % i == 0)
        {
            push(i);
            n = n / i;
        }
        i++;
    }
    print();
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    printf("Name: M.Vivek Reddy\n");
    printf("Roll No: BT23CSE048\n");
    printf("Current local time: %s", asctime(localTime));

    return 0;
}