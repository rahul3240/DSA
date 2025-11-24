#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node *start=NULL,*p;

void insert_sll(int item){
    p= (struct node * )malloc(sizeof(struct node));
    p->info=item;
    if(start==NULL){
        p->next=NULL;
        start=p;
    }
    else{
        p->next=NULL;
        struct node *last=start;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=p;
    }
}

void delete_beg(){
    struct node *temp;
    if (start==NULL)
        printf("SLL is Empty\n");
    else if(start->next==NULL){
        printf("delete element %d\n",start->info);
        free(start);
        start=NULL;
    }
    else{
        printf("delete element %d\n",start->info);
        temp=start;
        start=start->next;
        free(temp);
    }
}


void delete_end(){
    struct node *follow,*last;
    if (start==NULL)
        printf("SLL is Empty\n");
    else if(start->next==NULL){
        last=start;
        printf("delete element %d\n",last->info);
        free(last);
        start=NULL;
    }
    else{
        last=start;
        while(last->next!=NULL){
            follow=last;
            last=last->next;
        }
        printf("delete element %d\n",last->info);
        follow->next=NULL;
        free(last);
    }
}

void delete_any_pos(int pos){
    struct node *follow,*last;
    if (start==NULL)
        printf("SLL is Empty\n");
    else{
        last=start;
        int i=0;
        while(last!=NULL){
            if(i==pos-1)
                break;
            follow=last;
            last=last->next;
            i++;
        }
        if(last==NULL){
            printf("Position not fount!");
        }
        else{
            printf("delete element %d\n",last->info);
            follow->next=last->next;
            free(last);
        }
    }
}
        
    
int main(){
    int pos,choice,item;
    printf("Enter items (to stop enter -999):");
    scanf("%d",&item);
    while(item!=-999){
        insert_sll(item);
        scanf("%d",&item);
    }
    while(1){
        printf("Deletion\n");
        printf("1.deletion at begining\n2.deletion at end\n3.deletion at any position\n4.exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                delete_beg();
                break;
            case 2:
                delete_end();
                break;
            case 3:
                printf("Enter position:");
                scanf("%d",&pos);
                delete_any_pos(pos);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
