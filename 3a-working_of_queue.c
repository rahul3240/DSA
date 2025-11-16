#include<stdio.h>

#define MAX 5 //max size of queue

int queue[MAX];
int front=-1,rear=-1;

//function to insert an element into queue
void insert(int value){
    if (rear==MAX-1){
        printf("Queue Overflow! Cannot insert %d\n",value);
    }
    else{
        if (front==-1){
            front = 0;
        }
        rear++;
        queue[rear]=value;
        printf("%d inserted into queue\n",value);
    }
}

//function to delete an element from queue
void delete(){
    if(front==-1 || front>rear)
        printf("Queue Underflow! Queue is empty\n");
    else{
        printf("Deleted element: %d\n",queue[front]);
        front++;
    }
}

//function to display the elements from queue
void display(){
    if (front==-1 || front > rear)
        printf("Queue is empty\n");
    else{
        printf("Queue elements:");
        for (int i=front;i<=rear;i++)
            printf("%d\n",queue[i]);
        printf("\n");
    }
}

// void showfront(){
//     if (front == -1)
//         printf("There are no elements in queue\n");
//     else{
//         printf("The front element is %d",queue[front]);
//     }
// }
// void showrear(){
//     if (front == -1 || front>rear)
//         printf("There are no elements in queue\n");
//     else{
//         printf("The rear element is %d",queue[rear]);
//     }
// }

int main(){
    int choice,value;
    while(1){
        printf("\nQueue Operartions:\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        // printf("5.Show Front Element\n");
        // printf("6.Show Rear Element\n");

        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter valuie to insert:");
                scanf("%d",&value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3: 
                display();
                break;
            case 4:
                printf("Exiting Program...\n");
                return 0;
            // case 5:
            //     showfront();
            //     break;
            // case 6:
            //     showrear();
            //     break;
            default:
                printf("Invalid choice! Please try again\n");
        }
    }
    return 0;
}