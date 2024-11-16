#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max 100

int top = -1;
int stack_arr[max];
char infix[max];
char postfix[max];

int isempty() {
    return top == -1;
}

int isfull() {
    return top == max - 1;
}

void push(int data) {
    if (isfull()) {
        printf("Stack overflow\n");
        exit(1);
    }
    top++;
    stack_arr[top] = data;
}

int pop() {
    if (isempty()) {
        printf("Underflow\n");
        exit(1);
    }
    int value = stack_arr[top];
    top--;
    return value;
}

int post2in() {
    int i, a, b;
    for (int i = 0; i < strlen(postfix); i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(postfix[i] - '0');
        } else {
            a = pop();
            b = pop();
            switch (postfix[i]) {
                case '+':
                    push(b + a);
                    break;
                case '-':
                    push(b - a);
                    break;
                case '*':
                    push(b * a);
                    break;
                case '/':
                    if (a == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    push(b / a);
                    break;
                case '^':
                    push(pow(b, a));
                    break;
            }
        }
    }
    return pop();
}

int precedence(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int space(char c) {
    return c == ' ' || c == '\t';
}

void intopostfix() {
    int i = 0, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        if (!space(symbol)) {
            switch (symbol) {
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while ((next = pop()) != '(') {
                        postfix[j++] = next;
                    }
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while (!isempty() && precedence(stack_arr[top]) >= precedence(symbol)) {
                        postfix[j++] = pop();
                    }
                    push(symbol);
                    break;
                default:
                    postfix[j++] = symbol;
                    break;
            }
        }
    }
    while (!isempty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Terminate postfix string
}

void print() {
    printf("%s\n", postfix);
}

int main() {
    printf("Enter expression: ");
    scanf("%s", infix);
    intopostfix();
    int result = post2in();
    printf("Postfix expression: ");
    print();
    printf("Result: %d\n", result);
    return 0;
}
