#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
    };
void insert1(struct node **head,int data){
    struct node *p;
     p=malloc(sizeof(struct node));
     p->data=data;
     p->link=*head;
     *head=p;
     return;
}
void shift(struct node**head,int k,int count){
k=k%count;
struct node*p;
p=*head;
int i=0;
while(i<k){
    int temp;
    temp=p->data;
    while(p->link!=NULL){  
    p->data=p->link->data;
    p=p->link;
    }
p->data=temp;
p=*head;
i++;
}
return;
}
void print(struct node*head){
    struct node *p;
    p=head;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->link;
    }
    return ;
}
int main(){
    struct node *head;
    insert1(&head,40);
    insert1(&head,30);
    insert1(&head,90);
     insert1(&head,10);
    print(head);
    shift(&head,2,4);
    printf("shifted order is \n");
    print(head);
return 0;
}