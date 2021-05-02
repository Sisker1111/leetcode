
int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

void swap(int *x, int *y){
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}
void heapify(int *heap, int i){
    int parent = (i - 1) / 2;
    if (heap[i] > heap[parent]) {
        swap(&heap[i],&heap[parent]);
        heapify(heap, parent);
    }
}

void insertNode(int *heap, int n, int Key){
    n++;
    heap[n - 1] = Key;
    heapify(heap, n - 1);
}

void heapify_d(int *heap, int n, int i){
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    if (l < n && heap[l] > heap[largest])
        largest = l;
    if (r < n && heap[r] > heap[largest])
        largest = r;
    if (largest != i) {
        swap(&heap[i],&heap[largest]);
        heapify_d(heap, n, largest);
    }
}
  
// Function to delete the root from Heap
int deleteRoot(int *heap, int n){
    
    int MaxElement = heap[0];
    heap[0] = heap[n - 1];
    n--;
    heapify_d(heap, n, 0);
    return MaxElement;
}

int findKthLargest(int* nums, int numsSize, int k){
    int* heap = (int *)malloc(numsSize*sizeof(int));
    heap[0] = nums[0];
    for(int i=1; i<numsSize; i++){
        insertNode(heap, i, nums[i]);
    }
    int k_th;
    for(int i=0; i<k; i++){
        k_th = deleteRoot(heap, numsSize);
        numsSize--;
    }
    return k_th;
}