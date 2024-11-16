#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define max 4
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
int peek()
{
    if (isfull())
    {
        printf(" stack overflow");
        exit(1);
    }
    return stack_arr[top];
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
    /*another method 
    push(1);
    push(2);
    push(3);
    push(4);
    int data = pop();
    print();*/
    int choice, data;
    while (1)
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.print the top element \n");
        printf("4.print all\n");
        printf("5.quit\n");
        printf("enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element to be pushed\n");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            int value = pop();
            printf("deleted element is %d\n", value);
            break;
        case 3:
            printf("top element is %d\n", peek());
            break;
            case 4:
            print();
            break;
            case 5:
            exit(1);
        default:
        printf("wrong choice\n");
            break;
        }
    }

    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    printf("Name: M.Vivek Reddy\n");
    printf("Roll No: BT23CSE048\n");
    printf("Current local time: %s", asctime(localTime));
    return 0;
}