// concate queue
// check palindrome
// implement 2 queue using array
// use queue to reverse stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#define max 100
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
    front = (front + 1) % max;
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
int main()
{
    enqueue(10);
    enqueue(30);
    enqueue(20);
    int d = dequeue();
    printf("%d\n", d);
    print();
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    printf("Name: M.Vivek Reddy\n");
    printf("Roll No: BT23CSE048\n");
    printf("Current local time: %s", asctime(localTime));
    return 0;
}
