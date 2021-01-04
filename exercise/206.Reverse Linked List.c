/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    
   struct ListNode* cursor = NULL;
    while(head){
        
        struct ListNode* next = head->next ;
        head->next = cursor;
        cursor = head;
        head = next;
    }
    
    head = cursor;
    return head;
}