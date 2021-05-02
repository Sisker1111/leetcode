

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char * s, char * p, int* returnSize){
    *returnSize = 0;
    int *result = (int *)calloc(11000,sizeof(int));
    int *hash = (int *)calloc(26,sizeof(int));
    int *hash_valid = (int *)calloc(26,sizeof(int));
    int first = 1 , cnt_zero = 0;
    int len_p = strlen(p);
    int len_s = strlen(s);
    if( len_p > len_s )
        return result;
    for(int i=0; i < len_s ; i++){  
        hash[s[i]-97]--;
        if(i < len_p){
            hash[p[i]-97]++;
            hash_valid[p[i]-97] = 1;
        }
        if(hash_valid[s[i]-97] && !first){
            if(hash[s[i]-97] == 0) cnt_zero--;
            else if( hash[s[i]-97] + 1 == 0) cnt_zero++;
        }
        if( i+1 >= len_p ){
            if(first){
                for(int j=0; j < 26; j++ ){
                    if(hash[j] != 0 && hash_valid[j]){
                        cnt_zero++;
                    }
                }
                first = 0;
            }
            if(!cnt_zero)
                result[(*returnSize)++] = i-len_p+1;
            int tmp = s[i-len_p+1]-97;
            hash[tmp]++;
            if( hash_valid[tmp] ){
                if(hash[tmp] == 0) cnt_zero--;
                else if( hash[tmp] - 1 == 0 ) cnt_zero++;
            }
            continue;
        }
        
    }
    return result;

}