#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node *start=NULL,*p;

struct node* insert_sll(int item,struct node *start1){
    p= (struct node * )malloc(sizeof(struct node));
    p->info=item;
    if(start1==NULL){
        p->next=NULL;
        start1=p;
    }
    else{
        p->next=NULL;
        struct node *last=start1;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=p;
    }
    return start1;
}

void sort_sll(){
    struct node *i,*j,*min;
    int temp;
    if(start==NULL)
        printf("SLL is empty\n");
    else {
        for (i=start;i->next!=NULL;i=i->next){
            min=i;
            for (j=i->next;j!=NULL;j=j->next){
                if(j->info<i->info)
                    min=j;
            }
            temp=i->info;
            i->info=min->info;
            min->info=temp;
        }
    }
}

void reverse_sll(){
    struct node *cur=NULL,*temp;
    if(start==NULL)
        printf("SLL is empty\n");
    else{
        while(start != NULL){
            temp = start->next;   // save next node
            start->next = cur;    // reverse link
            cur = start;          // move cur forward
            start = temp;         // move start forward
        }
        start = cur;              // update head pointer
    }
}


struct node* concatinate_sll(struct node *temp_start){
    if(temp_start==NULL) return start;
    else if(start==NULL) return temp_start;
    else{
        struct node *temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=temp_start;
        return start;
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
    int pos,choice,item;
    printf("Enter items (to stop enter -999):");
    scanf("%d",&item);
    while(item!=-999){
        start=insert_sll(item,start);
        scanf("%d",&item);
    }
    struct node* temp_start=NULL;
    while(1){
        
        printf("1.sort sll\n2.reverse sll\n3.concatination\n4.display\n5.exit\n");
        printf("Enter choice:\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
               sort_sll();
                break;
            case 2:
                reverse_sll();
                break;
            case 3:
                printf("Enter items for 2nd sll (to stop enter -999):");
                scanf("%d",&item);
                while(item!=-999){
                    temp_start=insert_sll(item,temp_start);
                    scanf("%d",&item);
                }
                start=concatinate_sll(temp_start);
                break;
            case 4:
                display_sll();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
