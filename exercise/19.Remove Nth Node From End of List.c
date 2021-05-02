/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* ptr1 = head;
    struct ListNode* ptr2 = head;
    int step = 0;
    while(ptr1){
        step++;
        if(step > n && ptr1->next){
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    if( head == ptr2 && step==n){
        head = head->next;
    }
    else{
        ptr2->next = ptr2->next->next;
    }
    return head;

}