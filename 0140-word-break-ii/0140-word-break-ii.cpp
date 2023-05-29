class Solution {
public:
    vector<string> ans;
    
    
    
    void f(string &A,unordered_set<string> &d,int idx,string temp){
        if(idx >= A.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }

       // if(dp[idx] != -1) return dp[idx];

        string t = "";
        for(int i = idx;i<A.size();i++){
            t += A[i];
            if(d.find(t) != d.end()){
                f(A,d,i+1,temp+t+" ");
            }
        }

    }
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
         unordered_set<string> d(wordDict.begin(),wordDict.end());
        f(s,d,0,"");
        return ans;
    }
};