
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 3
int front = -1;
int rear = -1;
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
    front=(front+1)%max;
    int v = queue_arr[front];
    return v;
}
void print()
{
    for (int i = rear; i > front; i--)
    {
        printf("%d\n", queue_arr[i]);
    }
}
void reverse()
{
    for (int i = rear; i > front; i--)
    {
        
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    dequeue();
    enqueue(30);
    print();
    return 0;
}