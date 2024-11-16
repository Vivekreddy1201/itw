#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node{
    struct node *pp;
int data;
struct node*np;
};
void insert_at_beg(struct node **head,int data){
    struct node *t,*p;
    p=*head;
    t=malloc(sizeof(struct node));
    t->pp=NULL;
    t->data=data;
    t->np=*head;
    if(*head!=NULL){
    p->pp=t;
    }
    *head=t;
    return;
}
void insert_at_end(struct node **head,int data){
    struct node*t,*p;
     t=malloc(sizeof(struct node));
    t->pp=NULL;
    t->data=data;
    t->np=NULL;
    p=*head;
    while(p->np!=NULL){
        p=p->np;
    }
    p->np=t;
    t->pp=p;
    return;
}
void insert_at_pos(struct node **head,int pos,int data){
    struct node*t,*p;
     t=malloc(sizeof(struct node));
    t->pp=NULL;
    t->data=data;
    t->np=NULL;
    p=*head;
    int i=0;
    while(i<pos-2){
        p=p->np;
        i++;
    }
    t->np=p->np;
    p->np=t;
    t->pp=p;
    return;
   /* t->np=p;
    t->pp=p->pp;
    p->pp=t;
    *head=t;
    return;*/
}
void delete_at_beg(struct node **head){
    struct node*p,*t;
    p=*head;
    if(*head==NULL){
        return;
    }
    t=p->np;
    t->pp=NULL;
    *head=t;
    free(p);
    return;
}
void delete_at_end(struct node **head){
    struct node*p,*t;
    p=*head;
    while(p->np->np!=NULL){
        p=p->np;
    }
    t=p->np;
    p->np=NULL;
    free(t);
}
void delete_at_pos(struct node **head,int pos){
    struct node*p,*t;
    p=*head;
    int i=0;
    while (i<pos-1)
    {
        p=p->np;
        i++;
    }
    t=p->np;
    p->np=t->np;
    t->np->pp=p;
    free(t);
    return;
    
}
void print(struct node *head){
struct node*p=NULL;
p=head;
while(p!=NULL){
printf("%d\n",p->data);
p=p->np;
}
}
int main(){
    struct node*head;
    insert_at_beg(&head,10);
    insert_at_beg(&head,40);
    insert_at_end(&head,30);
    insert_at_pos(&head,3,20);
    delete_at_beg(&head);
    delete_at_end(&head);
    print(head);
        time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    printf("Name: M.Vivek Reddy\n");
    printf("Roll No: BT23CSE048\n");
    printf("Current local time: %s", asctime(localTime));
    return 0;
}
