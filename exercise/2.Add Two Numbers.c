/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node_t;
typedef Node_t * Node;

Node create_node(){
    Node temp = (Node)malloc(sizeof(Node_t));
    temp->val = 0;
    temp->next = NULL;
    return temp;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    int temp1, temp2, carry = 0;
    Node output = create_node();
    Node trace_t1 = l1;
    Node trace_t2 = l2;
    Node trace_o = output;
    while(trace_o){
        temp1 = temp2 = 0;
        if(l1){
            temp1 = l1->val;
            l1 = l1->next;
        }
        if(l2){
            temp2 = l2->val;
            l2 = l2->next;
        }
        temp1 = temp1 + temp2 + carry;
        if(temp1 >= 10){
            carry = 1;
            temp1 -= 10;
        }
        else carry = 0;
        trace_o->val = temp1;
        if(l1 || l2 || carry)
            trace_o->next = create_node();
        trace_o = trace_o->next;     
    }
     
    return output;
    
}