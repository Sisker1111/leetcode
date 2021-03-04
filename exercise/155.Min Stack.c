

#define SIZE 8000
typedef struct {
    int *num;
    int top;
    int min;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* obj = (MinStack *)malloc(sizeof(MinStack));
    obj->num = (int*)malloc(SIZE*sizeof(int));
    obj->top = -1;
    obj->min = 2147483647;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
  if( obj->top == SIZE )
      printf("Stack is full");
  obj->num[++(obj->top)] = x;  
  if( x < obj->min )
      obj->min = x;
}

void minStackPop(MinStack* obj) {
  if( obj->top == -1 )
    printf("Stack is empty");
  obj->top--;
  if( obj->num[obj->top+1] == obj->min ){
      obj->min = 2147483647;
       for(int i=0; i<=obj->top; i++)
        if( obj->num[i] < obj->min )
            obj->min = obj->num[i];
  }
}

int minStackTop(MinStack* obj) {
    if( obj->top == -1 )
        return 0;
    return obj->num[obj->top];
  
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    free(obj->num);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/