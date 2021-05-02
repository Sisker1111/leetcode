
typedef struct {
    int key;
    int valid;
} cache_queue;

typedef struct {
    int used;
    int value;
    int site;
} hash_map;

typedef struct {
    cache_queue* cache;
    hash_map* hash;
    int count;
    int top;
    int least;
    int capicity;
} LRUCache;

void check_least(LRUCache* obj){
    (obj->least)++;
    if(obj->count != 1){
        while(!obj->cache[obj->least].valid)
            (obj->least)++;
    }
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *obj = (LRUCache *)malloc(sizeof(LRUCache));
    obj->cache = (cache_queue *)malloc((capacity+18000)*sizeof(cache_queue));
    obj->hash = (hash_map *)malloc(3001*sizeof(hash_map));
    for(int i=0; i<capacity+18000; i++)
        obj->cache[i].valid = 0;
    for(int i=0; i<3001; i++)
        obj->hash[i].used = 0; 
    obj->capicity = capacity;
    obj->least = 0;
    obj->top = 0;
    obj->count = 0;
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if(obj->hash[key].used){
        obj->cache[obj->hash[key].site].valid = 0;
        obj->cache[obj->top].valid = 1;
        obj->cache[obj->top].key = key;
        
        if(obj->hash[key].site == obj->least)
            check_least(obj);
        obj->hash[key].site = obj->top;
        (obj->top)++;
        return obj->hash[key].value;
    }
    
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    
    obj->cache[obj->top].key = key;
    obj->cache[obj->top].valid = 1;
    obj->hash[key].value = value;
    
    if(obj->hash[key].used && obj->hash[key].site == obj->least )
        check_least(obj);
    if(obj->hash[key].used)
        obj->cache[obj->hash[key].site].valid = 0;
    obj->hash[key].site = obj->top;
    
    if(!obj->hash[key].used){
        if(obj->count == obj->capicity){
            obj->hash[obj->cache[obj->least].key].used = 0;
            check_least(obj);
        }
        else
            (obj->count)++;
        obj->hash[key].used = 1;
    }
    (obj->top)++;
}

void lRUCacheFree(LRUCache* obj) {
    free(obj); 
}


/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/