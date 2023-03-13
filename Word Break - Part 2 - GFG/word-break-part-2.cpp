//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    set<string > st;
    vector<string> ans;
    
    void f(int n,string s,string t,vector<string> &dict,int idx){
        if(idx == s.size()){
            t.pop_back();
            ans.push_back(t);
            return;
        }
        
        string x = "";
        
        for(int i = idx;i<s.size();i++){
            x += s[i];
            if(st.find(x) != st.end()){
                f(n,s,t+x+" ",dict,i+1);
            }
        }
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        for(auto it : dict) st.insert(it);
        f(n,s,"",dict,0);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends