/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *temp;

    if(head==NULL)
        printf("Linkeds list is already empty\n");
    else if(head->next==NULL){
        printf("Linked list has only one node\n");
        return head;
    }
    else{
        temp=head;
        int i=0;
        while(temp!=NULL){
            i++;
            temp=temp->next;
        }
        if(i%2==0){
            temp=head;
            int pos=(i/2);
            while(pos!=0){
                pos--;
                temp=temp->next;
            }
            return temp;
        }
        else{
            temp=head;
            int pos=(i-1)/2;
            while(pos!=0){
                pos--;
                temp=temp->next;
            }
            return temp;
        }
    }
    return 0;
}