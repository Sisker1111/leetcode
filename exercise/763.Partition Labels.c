

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* partitionLabels(char * S, int* returnSize){
    
    int *map = (int*)calloc(26, sizeof(int));
    int *size_array = (int*)calloc(50, sizeof(int));
    char *fisrt = S;
    int trace = 0, new_str = 0, acc = 0, max_end;
    while(*fisrt){
        map[(*fisrt)-97] = trace;
        fisrt++;
        trace++;
    }
    fisrt = S;
    trace = 0;
    *returnSize = 0;
    char last_char;
    while(*fisrt){
        if(!new_str){
            last_char = *fisrt;
            max_end = map[*fisrt-97];
            new_str = 1;
            if( !*(fisrt+1)  ){
                size_array[(*returnSize)++] = trace - acc + 1;
            }
        }
        else{
            if(*fisrt != last_char ){
                if(trace > map[last_char-97]){
                    size_array[(*returnSize)] = trace - acc ;
                    acc += size_array[(*returnSize)++];
                    new_str = 0;
                    continue;
                }
                if((map[*fisrt-97] > map[last_char-97])  && (trace < map[last_char-97]) ){
                    max_end = map[*fisrt-97];
                    last_char = *fisrt;
                }
            }
            if(trace == max_end){
                size_array[(*returnSize)] = trace - acc + 1;
                acc += size_array[(*returnSize)++];
                new_str = 0;
            }
        }
        fisrt++;
        trace++;
        
    }
    return size_array;
    

}