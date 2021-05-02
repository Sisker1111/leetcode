/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool Palindrome(struct ListNode** head, struct ListNode* current){
  
    if(current){
        bool res = Palindrome(head, current->next);
        res &= (current->val == (*head)->val);
        if(current->val == (*head)->val){
             *head = (*head)->next;
        }
        return res;
    }
    return true;
    
}

bool isPalindrome(struct ListNode* head){
    return Palindrome(&head, head);
}
