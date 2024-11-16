#include <stdio.h>
#include <stdlib.h>
#include<time.h>
struct node
{
    int data;
    struct node *link;
};
 void push(struct node **top, int data)
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
    p->link = *top;
    *top = p;
    return;
}
int pop(struct node **top)
{
    struct node *p;
    if (*top == NULL)
    {
        printf("stack underflow");
        exit(1);
    }
    p = *top;
    int value = p->data;
   * top = p->link;
    free(p);
    p = NULL;
    return value;
}
void print(struct node *top)
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
    struct node *top = NULL;
    struct node *top1 = NULL;
    struct node *top2 = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    printf("original stack is \n");
    print(top);
    while(top!=NULL){
    push(&top1,pop(&top));
   }
   while(top1!=NULL){
    push(&top2,pop(&top1));
   }
   while(top2!=NULL){
    push(&top,pop(&top2));
   }
   printf("reversed stack is \n");
    print(top);
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    printf("Name: M.Vivek Reddy\n");
    printf("Roll No: BT23CSE048\n");
    printf("Current local time: %s", asctime(localTime));

    return 0;
}