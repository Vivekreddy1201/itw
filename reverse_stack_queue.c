#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define max 100
int front = -1;
int rear = -1;
int top = -1;
int stack_arr[max];
int queue_arr[max];
void enqueue(int data)
{
    if (rear == max - 1)
    {
        exit(1);
    }
    rear = (rear + 1) % max;
    queue_arr[rear] = data;
}
int dequeue()
{
    if (rear == -1 && front == -1)
    {
        exit(1);
    }
    front = (front + 1) % max;
    int v = queue_arr[front];
    return v;
}
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
        printf("under flow");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack_arr[i]);
    }
}
void reverse()
{
    while (top != -1)
    {
        enqueue(pop());
    }
    while (front < rear)
    {
        push(dequeue());
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    reverse();
    print();
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    printf("Name: M.Vivek Reddy\n");
    printf("Roll No: BT23CSE048\n");
    printf("Current local time: %s", asctime(localTime));
return 0;
}