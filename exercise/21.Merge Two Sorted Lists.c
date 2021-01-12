/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* create_node(){
    struct ListNode* node ;
    node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node -> val = 0;
    node -> next = NULL;
    return node;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(!l1 && !l2 )
        return NULL;
    struct ListNode* merge_link;
    merge_link = create_node();
    struct ListNode** head = &merge_link;
    while(l1 || l2){
        if(!l1){
            (*head) = l2;
            break;
        }
        if(!l2){
            (*head) = l1;
            break;
        }
        if(l1->val <= l2->val){
            (*head) = l1;
            l1 = l1->next;
        }
        else{
            (*head) = l2;
            l2 = l2->next;
        }
        head = &(*head)->next;
    }
    
    return merge_link;

}