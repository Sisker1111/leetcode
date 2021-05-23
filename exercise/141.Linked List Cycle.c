/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    
    if(!head)
        return false;
    struct ListNode *slow =head , *fast = head->next;
    while( slow != fast ){
        if( !fast || !fast->next )
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
    
}