class Solution {
public:
    
    
    //int mx = -1e9;
    
    bool f(string &s1,string &s2){
        if(s1.size() != s2.size() + 1) return false;
        
        int i = 0;
        int j = 0;
        
        while(i < s1.size()){
            if(j < s2.size() and s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
        if(i == s1.size() and j == s2.size()) return true;
        
       return false;
    }
    
    static bool cmp(string &a,string &b){
        return a.size() < b.size();
    }
    
    
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        
        vector<int> dp(words.size(),1);
        
        int ans = -1;
        
        for(int i = 0 ;i<words.size();i++){
            
            for(int j = 0;j<i;j++){
                
                if(f(words[i],words[j]) and dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                }
                
            }            
            ans = max(ans,dp[i]);
        }
        
        return ans;
    }
};