struct HASH{
    char exist;
    unsigned short idx;
};

int lengthOfLongestSubstring(char * s){
    
    struct HASH * hash = (struct HASH *)malloc(127 * sizeof(struct HASH));
    for(int i=0; i < 127; i++){
        hash[i].exist = hash[i].idx = 0;
    }
    int max_count = 0, count = 0 , accu = 0;
    
    for(int i = 0; i < strlen(s); i++){
        char tmp =  s[i] ;
        if(!hash[tmp].exist || hash[tmp].idx < accu){
            hash[tmp].exist= 1;
            hash[tmp].idx = i;
            count++;
        }
        else{
            if(count > max_count)
                max_count = count;
            accu = hash[tmp].idx + 1;
            count = i - hash[tmp].idx;
            hash[tmp].idx = i;
        }
    }

    return (count > max_count) ? count : max_count;
}