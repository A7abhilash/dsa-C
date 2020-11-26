#include<stdio.h>
#include<stdlib.h>

struct STACK{
    int top;
    int arr[5];
};

typedef struct STACK stack;

int isEmpty(stack S){
    if(S.top==-1) return 1;
    return 0;
}

int isFull(stack S){
    if(S.top==4) return 1;
    return 0;
}

stack push(stack S){
    if(isFull(S)) printf("Stack overflow\n");
    else{
        printf("Enter the data:");
        scanf("%d",&S.arr[++S.top]);
        printf("Item pushed\n");
    }
    return S;
}

stack pop(stack S){
    if(isEmpty(S)) printf("Stack underflow\n");
    else printf("Item popped:%d\n",S.arr[S.top--]);
    return S;
}

int stackCount(stack S){
    return S.top+1;
}

int peek(stack S){
    if(isEmpty(S)){
        printf("Stack is empty\n");
        return 0;
    }
    return S.arr[S.top];
}

void display(stack S){
    if(isEmpty(S)){
        printf("Stack is empty\n");
        return;
    }
    printf("Total no. of items in stack:%d\n",stackCount(S));
    printf("Stack:\n");
    for (int i = S.top; i >=0  ; i--)
    {
        printf("%d\n",S.arr[i]);
    }
}

int main(){
    stack S;
    S.top=-1;
    int choice;

    while(1){
        printf("\n0.Exit\n1.Push\n2.Pop\n3.Display\n4.Get peek\n5.Total items in stack\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 0: exit(0);
            case 1: S=push(S);break;
            case 2: S=pop(S);break;
            case 3: display(S);break;
            case 4: printf("Top of stack:%d\n" ,peek(S));break;
            case 5: printf("Total no. of items in stack:%d\n",stackCount(S));break;
            default:printf("Enter proper option\n");
        }
    }
    return 0;
}