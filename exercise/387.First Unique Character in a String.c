int firstUniqChar(char * s){
   
    if(*s == '\0')
        return -1;
    int map[26] = {0};
    int idx = 0;
    while( *(s+idx) )
        map[*(s + (idx++)) - 'a']++;
   
    for(int i = 0; i < strlen(s); i++) {
if(map[*(s + i) - 'a'] == 1)
return i;
}
    return -1;
   
}