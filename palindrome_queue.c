#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10
int front = -1;
int rear=-1;
int queue_arr[max];
void push(int data){
    if(rear==max-1){
        exit(1);
    }
    rear=(rear+1)%max;
    queue_arr[rear]=data;
}
int pop(){
    if(rear==-1 && front==-1){
        exit(1);
    }
    front++;
    int v=queue_arr[front];
    return v;
}
void print(){
    for(int i=rear;i>front;i--){
        printf("%d\n",queue_arr[i]);
    }
}
void check(){
    int count=0;
         int j=0;
     for(int i=rear;i>front;i--){
        if(queue_arr[i]==queue_arr[j]){
        count++;
        j++;
        }
     }
     if(count==rear+1){
         printf("palindrome");
     }
     else{
          printf("not palindrome");
     }
}
int main(){
push(20);
push(10);
push(20);
push(10);
push(20);
print();
check();
return 0;
}