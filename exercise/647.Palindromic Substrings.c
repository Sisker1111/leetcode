

int countSubstrings(char * s){
    int res = 0;
    int len = strlen(s);
    int dp[len][len];
    for(int i=len-1; i>=0; i--){
        for(int j=i; j<len; j++){
            dp[i][j] = (s[i] == s[j]) && ( j-i <= 2  ||  dp[i+1][j-1]);
            if(dp[i][j]) res++;
        }
    }
    return res;
    
    
}