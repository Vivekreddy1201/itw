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
void reverse(struct node **head){
struct node *pn,*cn,*nn;
pn=NULL;
cn=nn=*head;
while(nn!=NULL){
nn=nn->link;
cn->link=pn;
pn=cn;
cn=nn;
}
*head=pn;
return;
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
void print2(struct node *head){
if(head==NULL){
return;
}
print2(head->link);
printf("%d\n",head->data);
}
void maxnmin(struct node*head){
struct node*p;
p=head;
int max;
int min=p->data;
max=p->data;
while(p!=NULL){
if(p->data>max){
max=p->data;
}
p=p->link;
}
printf("maximun is %d\n",max);
p=head;
while(p!=NULL){
if(p->data<min){
min=p->data;
}
p=p->link;
}
printf("minimum is %d\n",min);
}
void avg(struct node *head){
float avg=0;
int count=0;
struct node*p;
p=head;
while(p!=NULL){
count++;
avg=avg+(p->data);
p=p->link;
}
float x=(avg/count);
printf("avg is %f\n",x);
}
int main()
{
    struct node*head=NULL;
    // head=(struct node*)malloc(sizeof(struct node));
    // head->data=45;
    // head->link=NULL;
   insert1(&head,10);
   insert1(&head,20);
   insert2(&head,30);
   insert3(&head,40,2);
   print(head);
   count(head);
   reverse(&head);
   print(head);
   print2(head);
   maxnmin(head);
   avg(head);
    return 0;
}