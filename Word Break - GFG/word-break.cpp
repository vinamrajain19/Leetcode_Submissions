//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    
    unordered_set<string> s;
    int dp[1101];
    
    bool f(string &A,int idx){
        
        if(idx == A.size()) return true;
        
        if(dp[idx] != -1) return dp[idx];
        
        for(int i = idx;i<A.size();i++){
            string t = A.substr(idx,i-idx+1);
            if(s.find(t) != s.end()){
                if(f(A,i+1)) return dp[idx] =true;
            }
            
        }
        return dp[idx] =  false;
        
    }
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        memset(dp,-1,sizeof(dp));
        for(auto it : B) s.insert(it);
        return f(A,0);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends