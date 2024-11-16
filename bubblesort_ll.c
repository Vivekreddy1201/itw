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
void bubble(struct node **head){
    struct node*p;
    p=*head;
    for(int i=0;i<count-1;i++){
        for(int j=i+1;j<count,j++){
            if(p->data > p->link->data){
                int temp=p->link->data;
                p->link->data=p->data;
                p->data=temp;
            }
            p=p->link;
        }
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
   bubble(&head);
   print(head);
    return 0;
}