#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int info ;
    struct node *next;
};

struct node *start=NULL,*p;

void create_dll_end(){
    int item;
    printf("Enter item to insert(to stop enter -999):\n");
    scanf("%d",&item);
    while(item!=-999){
        p=(struct node *) malloc(sizeof(struct node));
        p->info=item;
        if(start==NULL){
            p->next=NULL;
            p->prev=NULL;
            start=p;
        }
        else {
            struct node *temp=start;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=p;
            p->prev=temp; 
            p->next=NULL; 
        }
        scanf("%d",&item);
    }
}

void insert_left_node(int item,int value){
    p=(struct node *) malloc(sizeof(struct node));
    p->info=item;
    if(start==NULL){
        p->next=NULL;
        p->prev=NULL;
        start=p;
    }
    else if(start->next==NULL){
        p->next=start;
        start->prev=p;
        p->prev=NULL;
        start=p;
    }
    else{
        struct node *temp=start,*follow;
        while(temp->info!=value){
            follow=temp;
            temp=temp->next;
        }
        follow->next=p;
        p->prev=follow;
        p->next=temp;
        temp->prev=p;
    }
}

void delete_node_value(int val){
    if(start==NULL)
        printf("dll is empty\n");
    else if(start->next==NULL){
        if(start->info==val){
            printf("Deleted %d\n",&start->info);
            free(start);
            start=NULL;
        }
        else
            printf("value %d not found\n",val);
    }
    else{
        struct node *temp=start,*follow;
        while(temp->info!=val){
            follow=temp;
            temp=temp->next;
        }
        if(temp!=NULL){
            printf("Deleted %d\n",&start->info);
            follow->next=temp->next;
            temp->next->prev=follow;
            free(temp);
        }
        else
            printf("value %d not found\n",val);
    }
}

void display_dll(){
    struct node *temp;
    if(start==NULL)
        printf("dll is empty\n");
    else{
        temp=start;
        while (temp!=NULL){
            printf("%d\n",temp->info);
            temp=temp->next;
        }
    }
}

int main(){
    int item,val,choice;
    while(1){
        printf("dll operation\n");
        printf("1.creation of dll\n2.insertion before a value\n3.deletion based on value\n4.display\n5.exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                create_dll_end();
                break;
            case 2:
                printf("Enter value before which to insert item:");
                scanf("%d",&val);
                printf("Enter item insert:");
                scanf("%d",&item);
                insert_left_node(item,val);
                break;
            case 3:
                printf("Enter value to delete:");
                scanf("%d",&val);
                delete_node_value(val);
                break;
            case 4:
                display_dll();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}