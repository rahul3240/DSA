#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node *start=NULL,*p,*q,*last;

void insert_beg(int item){
    p=(struct node *) malloc(sizeof(struct node));
    p->info=item;

    if (start==NULL){
        p->next=NULL;
        start=p;
        last=p;
    }
    else{
        p->next=start;
        start=p;
    }
}

void insert_end(int item){
    p=(struct node *) malloc(sizeof(struct node));
    p->info=item;

    if (start==NULL){
        p->next=NULL;
        start=p;
        last=p;
    }
    else{
        p->next=NULL;
        last->next=p;
        last=p;
    }
}

void insert_any_pos(int pos,int item){
    struct node *temp = start;
    int i=0;
    p = malloc(sizeof(struct node));
    p->info=item;

    while(1){
        i++;
        if(start==NULL){
            p->next=NULL;
            start=p;
            last=p;
            break;
        }
        else if(i==pos-1){
            q=temp->next;
            temp->next=p;
            p->next=q;
            break;
        }
        temp=temp->next;
    }
    
}


void display_sll(){
struct node *temp;
temp=start;
    if(start==NULL)
        printf("No Elements to display\n");
    else{
        printf("The elements of sll are \n");
        while(temp!=NULL){
            printf("%d\n",temp->info);
            temp=temp->next;
        }
    }
}


int main(){
    int pos=0,item,choice;

    while(1){
        printf("\nSingly Linked List\n");
        printf("1.Insert at begining\n2.insert at end\n3.insert at any position\n4.display\n5.exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter item to insert:");
                scanf("%d",&item);
                insert_beg(item);
                break;
            case 2:
                printf("Enter item to insert:");
                scanf("%d",&item);
                insert_end(item);
                break;
            
            case 3:
                printf("Enter position and item to insert:");
                scanf("%d %d",&pos,&item);
                insert_any_pos(pos,item);
                break;
            case 4:
                display_sll();
                break;
            case 5:
                printf("Exiting...");
                exit(0);
                break;
            default:
                printf("Invalid Choice!\n");

        }
    }
    return 0;
}