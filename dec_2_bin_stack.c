#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define max 100
int top = -1;
int stack_arr[max];
int isfull()
{
    if (top == max - 1)
        return 1;
    else
        return 0;
}
void push(int data)
{
    if (isfull())
    {
        //(top==max-1)
        printf(" stack overflow");
        exit(1);
    }
        top = top + 1;
        stack_arr[top] = data;
}
void print()
{
    if (top==-1)
    {
        // top<0
        printf("under flow");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%d", stack_arr[i]);
    }
}
int main(){
    int n;
    printf("enter the number \n");
    scanf("%d",&n);
    int v;
    while(n>0){
        v=n%2;
        push(v);
        n=n/2;
    }
    printf("binary is \n");
    print();
      time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    printf("Name: M.Vivek Reddy\n");
    printf("Roll No: BT23CSE048\n");
    printf("Current local time: %s", asctime(localTime));

}