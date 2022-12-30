//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string>> ans;
    
    vector<vector<string> > Anagrams(vector<string>& s) {
        //code here
        
        map<string,vector<string>> m;
        for(int i = 0;i<s.size();i++){
            string t = s[i];
            sort(t.begin(),t.end());
            
            m[t].push_back(s[i]);
        }
        
        for(auto it : m){
            vector<string> x;
            for(auto t : it.second){
                x.push_back(t);
            }
            ans.push_back(x);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends