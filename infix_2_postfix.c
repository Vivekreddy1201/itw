#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
int top = -1;
char stack_arr[max];
char infix[max];
char postfix[max];
int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if (top == max - 1)
        return 1;
    else
        return 0;
}
void push(char data)
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
char pop()
{
    if (isempty())
    {
        //(top==-1)
        printf("under flow");
        exit(1);
    }
    char value = stack_arr[top];
    top = top - 1;
    return value;
}
int precedence(char symbol){
    switch (symbol)
    {
        case '+':
        return 1;
        case '-':
        return 1;
        case '*':
        return 2;
        case '/':
        return 2;
        case '^':
        return 3;
        default:
        return 0;
    }
}
int space(char c){
    if(c==' '||c=='\t')
    return 1;
    else
    return 0;
}
void intopostfix(){
    int i=0;
    int j=0;
    char symbol;
    char next;
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        if(!space(symbol)){
        switch (symbol)
        {
        case '(':
        push(symbol);
            break;
        case ')':
        while((next=pop())!='('){
        postfix[j++]=next;
        }
        break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        while(!isempty() && precedence(stack_arr[top]) <= precedence(symbol)){
            postfix[j++]=pop();
        }
            push(symbol);
            break;

        default:
        postfix[j++]=symbol;
            break;
        }
    }
    }
    while(!isempty()){
        postfix[j++]=pop();
        postfix[j]='\0';
    }
}
void print(){
    int i=0;
    while(postfix[i]){
        printf("%c",postfix[i]);
        i++;
    }
    printf("\n");
}
int main(){
    printf("enter expression");
    scanf("%s",infix);
    intopostfix();
    print();
    return 0;
}