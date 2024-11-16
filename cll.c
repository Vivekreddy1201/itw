//check given string is palindrome or not
//check whether given expression has balance parenthesis
//create an array and use two stacks
//convert and print conversion of decimal into binary(recursion)
//convert using stack

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *np;
};
void insert1(struct node **head,int data){
struct node *p=malloc(sizeof(struct node));
p->data=data;
p->np=*head;
*head=p;
}
void insertend(struct node **head,int data){
    struct node *p,*t;
    t=*head;
    while(t->np!=head){
        t=t->np;
    }
    t->np=p;
    p->data=data;
    p->np=head;
}
int main(){
     struct node*head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->np=NULL;
     insert1(&head,10);
     insertend(&head,20);
   return 0;
}