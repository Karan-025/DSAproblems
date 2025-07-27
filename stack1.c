#include <stdio.h>
#define MAX 5   

int stack[MAX];
int top = -1;   

int isEmpty() {
    return top == -1;
}


int isFull() {
    return top == MAX - 1;
}


void push(int data) {
    if (isFull()) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = data;
    printf("%d pushed into stack\n", data);
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}


int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top];
}


int main() {
    push(10);
    push(20);
    push(30);
    
    printf("Top element is %d\n", peek());
    
    printf("Popped element is %d\n", pop());
    printf("Top element after pop is %d\n", peek());
    
    return 0;
}
