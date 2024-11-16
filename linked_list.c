#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*link;
};
void count(struct node*head){
int count=0;
struct node *ptr=NULL;
ptr=head;
while(ptr!=NULL){
ptr=ptr->link;
count++;
}
printf("%d",count);
}
int main()
{
    struct node*head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    printf("%d\n",head->link);
    struct node* current=NULL;
    current=malloc(sizeof(struct node));
    current->data=99;
    current->link=NULL;
    head->link=current;
   printf("%d\n",head->link);
   count(head);
    return 0;
}