class Solution {
public:
    int dp[50001][2][2];
    int f(vector<int> &s,int i,int alice,int bob){
        if(i >= s.size()) return 0;
        
        if(dp[i][alice][bob] != -1) return dp[i][alice][bob];
        
        int ans;
        int sum = 0;
        
        if(alice){
            ans = -1e9;
            for(int j = i;j < i+3 and j < s.size();j++){
                sum += s[j];
                ans = max(ans,sum + f(s,j+1,0,1));
            }
        }
        else{
            ans = 1e9;
             for(int j = i;j < i+3 and j<s.size();j++){
                //sum += s[j];
                ans = min(ans,f(s,j+1,1,0));
            }
        }
        
        return dp[i][alice][bob] = ans;
    }
    
    string stoneGameIII(vector<int>& s) {
        memset(dp,-1,sizeof(dp));
        int to = 0;
        for(auto it :s) to += it;
        
        int a = f(s,0,1,0);
        int b = to - a;
        
        if(b > a) return "Bob";
        else if(a > b) return "Alice";
        else return "Tie";
    }
};