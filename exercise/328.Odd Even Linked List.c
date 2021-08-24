/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    
    if(!head)
        return NULL;
    if(!head->next)
        return head;
    struct ListNode* start_link1 = head;
    struct ListNode* start_link2 = head->next;
    struct ListNode* curosr = head->next;
    while( head->next && head->next->next ){
        struct ListNode* tmp = curosr->next->next;
        head->next =  head->next->next;
        if(!tmp){
            head = head->next;
            goto jump;
        }
        curosr->next = tmp;
        head = head->next;
        curosr = curosr->next;
    }
    
    
    if(head->next == NULL){
        curosr -> next = NULL;
        head->next = start_link2;
    }
    else{
        jump:
        curosr -> next = NULL;
        head->next = start_link2;
    }  
    
    return start_link1;
}