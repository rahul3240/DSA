#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int front=-1,rear=-1,queue[MAX];

void insertpq(){
    int item;
    if(rear==MAX-1)
        printf("Queue Overflow\n");
    else if(front==-1){
        printf("Enter item to insert:");
        scanf("%d",&item);
        front=0;
        rear=0;
        queue[rear]=item;
        printf("%d inserted into queue\n",item);
    }
    else{
        printf("Enter item to insert:");
        scanf("%d",&item);
        int j=rear;
        while(j>=0 && queue[j]>item){
            queue[j+1]=queue[j];
            printf("%d\n",queue[j]);
            printf("%d\n",queue[j+1]);
            j--;
        }
        queue[j+1]=item;
        rear++;
        printf("%d inserted into queue\n",item);
    }
}

void deletepq(){
    if (front==-1){
        printf("Queue Underflow!\n");
    }
    else if(front==rear){
        printf("%d is deleted from queue\n",queue[front]);
        front=-1;
        rear=-1;
    }
    else{
        printf("%d is deleted from queue\n",queue[front]);
        front++;
    }
}

void displaypq(){
    if (front==-1){
        printf("Queue Underflow!\n");
    }
    else{
        printf("Queue Elements\n");
        for(int i=front;i<=rear;i++){
            printf("%d\n", queue[i]);
        }
    }
}

int main(){
    int choice;
    while (1){
        printf("Priority Queue\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                insertpq();
                break;
            case 2:
                deletepq();
                break;
            case 3:
                displaypq();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}