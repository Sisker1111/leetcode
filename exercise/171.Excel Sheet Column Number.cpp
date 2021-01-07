class Solution {
public:
    int titleToNumber(string s) {
        int result=0;
        for(int i=0;i<s.size();i++){
            result+=(s[i]-'A'+1)*pow(26,s.size()-i-1);
        }
        return result;
        
    }
};