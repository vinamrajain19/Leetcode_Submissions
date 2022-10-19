//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  
    bool ispal(string S,int i,int j){
        while(i <= j){
            if(S[i] != S[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    vector<vector<string>> ans;
    void solve(int idx,string S,vector<string> temp){
        if(idx == S.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx;i<S.size();i++){
            if(ispal(S,idx,i)){
                temp.push_back(S.substr(idx,i-idx+1));
                solve(i+1,S,temp);
                temp.pop_back();
            }
            
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<string> temp;
        solve(0,S,temp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends