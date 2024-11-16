#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define max 100
int top = -1;
int stack_arr[max];
void isfull(){
    if(top==max-1){
        return 1;
    }
    else 
    return 0;
}
void push(int data){
    if(isfull()){
        exit(1);
    }
    stack_arr[top]=data;
    top++;
}
void palindrome(char *s){
int i=0;
while(s[i]!=){
    push(s[i]);
    i++;
}i++;
while(s[i]){

}
                                   
}
int main(){
    char s[100];
    printf("enter string ");
    scanf("%s",s);
    palindrome(s);
        time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    printf("Name: M.Vivek Reddy\n");
    printf("Roll No: BT23CSE048\n");
    printf("Current local time: %s", asctime(localTime));

}