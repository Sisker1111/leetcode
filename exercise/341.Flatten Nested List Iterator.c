/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */
struct NestedNode {
    int val;
    struct NestedNode *next;
};
struct NestedIterator {
    struct NestedNode *head;
};
struct NestedNode *create(int val){
    struct NestedNode *node = (struct NestedNode *)malloc(sizeof(struct NestedNode));
    node->val = val;
    node->next = NULL;
    return node;
}
void recursive(struct NestedNode **r_node, struct NestedNode *node, struct NestedInteger** nestedList, int list_size){
   
    for(int i=0; i<list_size; i++){
        if(NestedIntegerIsInteger(*(nestedList+i))){
            node->next = create(NestedIntegerGetInteger(*(nestedList+i)));
            node = node->next;
            *r_node = node;
        }
        else{    
            struct NestedNode *check = *r_node;
            int size = NestedIntegerGetListSize(*(nestedList+i));
            if(!size) continue;
            recursive(r_node, node, NestedIntegerGetList(*(nestedList+i)),
                              size );
            if(*r_node != check) node = *r_node;
        }
    }
   
     
}
struct NestedIterator *nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize) {
    struct NestedIterator *new_nested = (struct NestedIterator *)malloc(sizeof(struct NestedIterator));
    new_nested->head = create(0);
    struct NestedNode *cur = new_nested->head;
    struct NestedNode *r_node = NULL;
   
    for(int i=0; i<nestedListSize; i++){
        if( NestedIntegerIsInteger(*(nestedList+i)) ){
            cur->next = create(NestedIntegerGetInteger(*(nestedList+i)));
            cur = cur->next;
        }
        else{
            struct NestedNode *check = r_node;
            int size = NestedIntegerGetListSize(*(nestedList+i));
            if(!size) continue;
            recursive(&r_node, cur, NestedIntegerGetList(*(nestedList+i)),
                              size );
            if(r_node != check) cur = r_node;         
        }
    }
    return new_nested;
   
}

bool nestedIterHasNext(struct NestedIterator *iter) {
   
    struct NestedNode *node = iter->head->next;
   
    if(node){
        iter->head = node;
        return 1;
    }
    else
        return 0;
}

int nestedIterNext(struct NestedIterator *iter) {
    return iter->head->val;
}

/** Deallocates memory previously allocated for the iterator */
void nestedIterFree(struct NestedIterator *iter) {
    free(iter);
}

/**
 * Your NestedIterator will be called like this:
 * struct NestedIterator *i = nestedIterCreate(nestedList, nestedListSize);
 * while (nestedIterHasNext(i)) printf("%d\n", nestedIterNext(i));
 * nestedIterFree(i);
 */