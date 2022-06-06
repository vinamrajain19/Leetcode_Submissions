class Solution {
public:
    bool comapre(string &s1,string &s2){
        
        if(s1.size() != s2.size() + 1) return false;
        
        int i = 0;
        int j = 0;
        
        while(i<s1.size()){
            
            if(j<s2.size() and s1[i] == s2[j]){
                i++;
                j++;
            }
            else i++;
        }
        
        if(i == s1.size() and j == s2.size()) return true;
        return false;
    }
    
    static bool comp(string &s1,string &s2){
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        
        int len = INT_MIN;
        sort(words.begin(),words.end(),comp);
        
        int n = words.size();
        vector<int> dp(n,1);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(comapre(words[i],words[j]) && dp[j] + 1 > dp[i]){
                    dp[i] = 1 + dp[j];
                }
            }
            len = max(len,dp[i]);
        }
        return len;
    }
};