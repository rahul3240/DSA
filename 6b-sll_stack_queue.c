#include<stdio.h>
#include<stdlib.h>

// If not ran using normal run then ↓
// gcc .\file.c -o stackqueue.exe
// .\stackqueue.exe

struct node {
    int info;
    struct node *next;
};

struct node *p,*top=NULL,*front=NULL,*rear=NULL;


void insert_stack_beg(int item){
    p=(struct node *) malloc(sizeof(struct node));
    p->info=item;

    if (top==NULL){
        p->next=NULL;
        top=p;
    }
    else{
        p->next=top;
        top=p;
    }
}

void delete_stack_beg(){
    struct node *temp;
    if (top==NULL)
        printf("Stack is Empty\n");
    else if(top->next==NULL){
        temp=top;
        printf("delete element %d\n",temp->info);
        free(temp);
        top=NULL;
    }
    else{
        temp=top;
        top=top->next;
        printf("deleted element %d\n",temp->info);
        free(temp);
    }
}


void insert_queue_end(int item){
    p=(struct node *) malloc(sizeof(struct node));
    p->info=item;

    if (rear==NULL){
        p->next=NULL;
        front=p;
        rear=p;
    }
    else{
        p->next=NULL;
        rear->next=p;
        rear=p;
    }
}

void delete_queue_beg(){
    struct node *temp;
    if (front==NULL)
        printf("Queue is Empty\n");
    else if(front==rear){
        temp=front;
        front=NULL;
        rear=NULL;
        printf("delete element %d\n",temp->info);
        free(temp);
    }
    else{
        temp=front;
        front=front->next;
        printf("deleted element %d\n",temp->info);
        free(temp);
    }
}

void display_sll_stack(){
    struct node *temp;
    if(top==NULL)
        printf("Stack is Empty\n");
    else{
        temp=top;
        printf("The elements of Stack are:\n");
        while(temp!=NULL){
            printf("%d\n",temp->info);
            temp=temp->next;
        }
    }
}

void display_sll_queue(){
    struct node *temp;
    if(front==NULL)
        printf("Queue is Empty\n");
    else{
        temp=front;
        printf("The elements of Queue are:\n");
        while(temp!=NULL){
            printf("%d\n",temp->info);
            temp=temp->next;
        }
    }
}

int main(){
    int choice1=0,choice2,item;

    while(choice1!=1 && choice1!=2){
        printf("implementation of Stack and Queue Using Singly Linked List\n");
        printf("1.Stack\n2.Queue\n");
        printf("Enter your choice:");
        scanf("%d",&choice1);
        switch(choice1){
            case 1:
                while(1){
                    printf("implementation of Stack Using Singly Linked List\n");
                    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
                    printf("Enter your choice:");
                    scanf("%d",&choice2);
                    switch(choice2){
                        case 1:
                            printf("Enter element to Insert:");
                            scanf("%d",&item);
                            insert_stack_beg(item);
                            break;
                        case 2:
                            delete_stack_beg();
                            break;
                        case 3:
                            display_sll_stack();
                            break;
                        case 4:
                            exit(0);
                            break;
                        default:
                            printf("Invalid Choice:");
                    }
                }
                break;
            case 2:
                while(1){
                    printf("implementation of Queue Using Singly Linked List\n");
                    printf("1.Insertion-queue\n2.Deletion-queue\n3.Display-queue\n4.Exit\n");
                    printf("Enter your choice:");
                    scanf("%d",&choice2);
                    switch(choice2){
                        case 1:
                            printf("Enter element to Insert:");
                            scanf("%d",&item);
                            insert_queue_end(item);
                            break;
                        case 2:
                            delete_queue_beg();
                            break;
                        case 3:
                            display_sll_queue();
                            break;
                        case 4:
                            exit(0);
                            break;
                        default:
                            printf("Invalid Choice\n");
                    }
                }
                 break;   
            default:
                printf("invalid Choice\n");
        }
    }
    return 0;
}
