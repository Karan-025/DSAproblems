#include <stdio.h>
#define size 100
int rear1=-1,rear2=-1;
int front1=-1,front2=-1;
int q1[size];
int q2[size];

int isFull1(){
    if(rear1==size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty1(){
    if(front1==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int n){
    if(isFull1()){
        printf("OF\n");
        return;
    }
    else{
        if(front1==-1){
            front1=0;
        }
        rear1++;
        q1[rear1] = n;        
    }
}

void pop(){
    if(isEmpty1()){
        printf("UF\n");
        return;
    }
    else{
        for(int i=rear1;i>=front1;i--){
            rear2++;
            q2[rear2]=q1[i];
            rear1--;
        }
        if(front2==-1){
            front2=0;
        }
        
        printf("The element removed: %d\n",q2[front2]);
        front2++;

        for(int i=rear2;i>=front2;i--){
            rear1++;
            q1[rear1]=q2[i];
            rear2--;
        }
    }
}

void display(){
    for(int i=rear1;i>=front1;i--){
        printf("%d\n",q1[i]);
    }
    printf("\n");
}




int main(){
    push(1);
    push(2);
    push(3);
    push(4);

    display();

    pop();

    display();


    return 0;
}