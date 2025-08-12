#include <stdio.h>
#define size 100

int s1[size],s2[size];
int top1=-1,top2=-1;


int isEmpty(){
    if(top1==-1){
        return 1;
    }
    else{
        return 0;
    }
}


int isFull(){
    if(top1==size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enque(int n){
    if(isFull()){
        printf("OF\n");
        return;
    }
    else{
        top1++;
        s1[top1] = n;
    }
}

void deque(){
    if(isEmpty()){
        printf("UF\n");
        return;
    }
    else{
        for(int i=top1;i>=0;i--){
            top2++;
            s2[top2] = s1[i];
            top1--;
        }

        printf("Element removed: %d\n",s2[top2]);
        top2--;

        for(int i=top2;i>=0;i--){
            top1++;
            s1[top1] = s2[i];
            top2--;
        }
    }
}

void display(){
    for(int i=0;i<=top1;i++){
        printf("%d ",s1[i]);
    }
    printf("\n");
}

int main(){
    enque(1);
    enque(2);
    enque(3);
    enque(4);

    display();

    deque();

    display();

    return 0;
}