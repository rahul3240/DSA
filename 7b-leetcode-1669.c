/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode *temp1=list1,*temp2=list1;

    if(list1==NULL)
        return list2;
    else if(list2==NULL)
        return list1;
    else {
        for(int i=0;i<a-1;i++)
            temp1=temp1->next;
        
        for(int i=0;i<=b;i++)
            temp2=temp2->next;
        
        temp1->next=list2;
        while(temp1->next!=NULL)
            temp1=temp1->next;
        
        temp1->next=temp2;
        return list1;
    }
}