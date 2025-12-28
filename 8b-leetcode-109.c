/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if(head==NULL)
        return NULL;
    else if(head->next==NULL){
        struct TreeNode *root=(struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val=head->val;
        root->left=root->right=NULL;
        return root;
    }
    struct ListNode *falfollow,*follow=head,*temp=head;

    while(temp!=NULL && temp->next!=NULL){
        falfollow=follow;
        follow=follow->next;
        temp=temp->next->next;
    }
    struct TreeNode *root=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val=follow->val;
    falfollow->next=NULL;
    root->left=sortedListToBST(head);
    root->right=sortedListToBST(follow->next);
    return root;
}