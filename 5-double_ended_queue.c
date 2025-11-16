#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int front=-1,rear=-1,queue[MAX];

void insertfr(){
    int item;
    if(rear==MAX-1)
        printf("Queue Overflow\n");
    else if(front==-1){
        printf("Enter item to insert:");
        scanf("%d",&item);
        front=0;
        rear=0;
        queue[front]=item;
        printf("%d inserted into front\n",item);
    }
    else{
        printf("Enter item to insert:");
        scanf("%d",&item);
        int j=rear;
        while(j>=front){
            queue[j+1]=queue[j];
            j--;
        }
        rear++;
        queue[front]=item;
        
        printf("%d inserted into front\n",item);
    }
}

void deletefr(){
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

void insertre(){
    int item;
    if(rear==MAX-1)
        printf("Queue Overflow\n");
    else if(front==-1){
        printf("Enter item to insert:");
        scanf("%d",&item);
        front=0;
        rear=0;
        queue[rear]=item;
        printf("%d inserted into rear\n",item);
    }
    else{
        printf("Enter item to insert:");
        scanf("%d",&item);
        rear++;
        queue[rear]=item;
        printf("%d inserted into rear\n",item);
    }
}

void deletere(){
    if (front==-1){
        printf("Queue Underflow!\n");
    }
    else if(front==rear){
        printf("%d is deleted from queue\n",queue[rear]);
        front=-1;
        rear=-1;
    }
    else{
        printf("%d is deleted from rear\n",queue[rear]);
        rear--;
    }
}

void displaydq(){
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
        printf("Double ended Queue\n");
        printf("1.Front Insert\n2.rear insert\n3.front delete\n4.rear delete\n5.Display\n6.Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                insertfr();
                break;
            case 2:
                insertre();
                break;
            case 3:
                deletefr();
                break;
            case 4:
                deletere();
                break;
            case 5:
                displaydq();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}