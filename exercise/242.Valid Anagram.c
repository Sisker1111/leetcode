

bool isAnagram(char * s, char * t){
    int map[26]={0};
    if(strlen(t) != strlen(s))
        return false;
    while(*s){
        map[(*s++) -'a']++;
        map[(*t++) -'a']--;
    }
    for(int i=0 ;i < 26 ;i++){
        if(map[i])
            return false;
    }
    return true;
    
}