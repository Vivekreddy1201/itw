#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*link;
};
void insert1(struct node **head,int data){
struct node *p=malloc(sizeof(struct node));
p->data=data;
p->link=*head;
*head=p;
}
void insert2(struct node **head,int data){
struct node*p=malloc(sizeof(struct node));
p->data=data;
p->link=NULL;
struct node*t=*head;
while(t->link!=NULL){
t=t->link;
}
t->link=p;
}
void print(struct node *head){
struct node*p=NULL;
p=head;
while(p!=NULL){
printf("%d\n",p->data);
p=p->link;
}
}
void selection(struct node **head){
    struct node*p;
    p=*head;
    while(p!= NUll){
    int min=p->data;
        if(p->data < min)
        min=p->data;
        p=p->link;
    }
}
int main()
{
    struct node*head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
   insert1(&head,10);
   insert1(&head,20);
   insert2(&head,30);
   print(head);
   selection(&head);
   print(head);
    return 0;
}