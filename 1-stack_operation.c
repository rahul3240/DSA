#include<stdio.h>
#include<stdlib.h>

#define size 5
int stack[size],top=-1;

void push(int value){
    if (top==size-1)
        printf("Stack Overflow!\n");
    else{
        top++;
        stack[top]=value;
        printf("%d inserted into stack\n",value);
    }
}

void pop(){
    if (top==-1)
        printf("Stack Underflow!\n");
    else{
        printf("%d deleted from stack\n",stack[top]);
        top--;
    }
}

void display(){
    if (top==-1)
        printf("Stack Underflow!\n");
    else{
        printf("Elements od stack are:\n");
        for (int i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}


int main(){
    int choice,value;
    while(1){
        printf("Stack operations\n");
        printf("1.push\n2.pop\n3.display\n4.exit\n");

        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value to push:");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...");
                exit(0);
                break;
            default:
                printf("Enter a valid choice\n");
        }
    }
    return 0;
}