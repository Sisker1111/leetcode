char * longestPalindrome(char * s){
    int len = strlen(s);
    char *res = (char *)malloc((len+1)*sizeof(char));
    int longest = 0;
    int dp[len][len]={0};
    for(int i=len-1; i>=0; i--){
        for(int j=i; j<len; j++){
            dp[i][j] = (s[i] == s[j]) && ( j-i <= 2  ||  dp[i+1][j-1]);
            if(dp[i][j] && (j-i+1) > longest){
                for(int k=0 ;k<=j-i; k++)
                    res[k] = s[k+i];
                longest = j-i+1;
            }
            
        }
    }
    res[longest] = '\0';
    return res;
}