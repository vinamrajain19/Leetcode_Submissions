class Solution {
public:
    
    int dp[301];
bool f(string A,unordered_set<string> &d,int idx){
    if(idx >= A.size()) return true;
    
    if(dp[idx] != -1) return dp[idx];
    
    string t = "";
    for(int i = idx;i<A.size();i++){
        t += A[i];
        if(d.find(t) != d.end()){
            if(f(A,d,i+1)) return dp[idx] = true;
        }
    }
    
    return dp[idx] = false;
    
}

int w(string A, vector<string> &B) {
    memset(dp,-1,sizeof(dp));
    unordered_set<string> d(B.begin(),B.end());
    return f(A,d,0);
}

    
    bool wordBreak(string s, vector<string>& wordDict) {
        return w(s,wordDict);
    }
};