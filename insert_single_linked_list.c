#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*link;
};
void count(struct node*head){
int count=0;
struct node *ptr;
ptr=head;
while(ptr!=NULL){
ptr=ptr->link;
count++;
}
printf("%d\n",count);
}
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
void insert3(struct node **head,int data,int pos){
int i=1;
struct node*p,*newnode;
p=*head;
while(i<pos-1){
p=p->link;
i++;
}
newnode=malloc(sizeof(struct node));
newnode->data=data;
newnode->link=p->link;
p->link=newnode;
}
void print(struct node *head){
struct node*p=NULL;
p=head;
while(p!=NULL){
printf("%d\n",p->data);
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
   insert3(&head,40,2);
   print(head);
   count(head);
    return 0;
}