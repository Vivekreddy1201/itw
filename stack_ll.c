#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node
{
    int data;
    struct node *link;
} *top = NULL;
void push(int data)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("stack overflow");
        exit(1);
    }
    p->data = data;
    p->link = NULL;
    p->link = top;
    top = p;
}
int pop()
{
    struct node *p;
    if (top == NULL)
    {
        printf("stack underflow");
        exit(1);
    }
    p = top;
    int value = p->data;
    top = p->link;
    free(p);
    p = NULL;
    return value;
}
int peek()
{
    if (top == NULL)
    {
        printf("stack underflow");
        exit(1);
    }
    return top->data;
}
void print()
{
    struct node *t;
    t = top;
    if (t == NULL)
    {
        printf("stack underflow");
        exit(1);
    }
    while (t != NULL)
    {
        printf("%d\n", t->data);
        t = t->link;
    }
    return;
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(400);
    int data = pop();
    printf("deleted element is %d\n", data);
    printf("remaing elements are :\n");
    print();
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    printf("Name: M.Vivek Reddy\n");
    printf("Roll No: BT23CSE048\n");
    printf("Current local time: %s", asctime(localTime));
}