//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
       unordered_map<char,int> m;
        for(auto it: t) m[it]++;
        int count = m.size();
        
        
        int i = 0;
        int ans = 1e9;
        string x;
        int j = 0;
        
        while(j<s.size()){
            
            if(m.find(s[j]) != m.end()){
                m[s[j]]--;
                if(m[s[j]] == 0) count--;
            }
            
            if(count == 0){
                
               while(count == 0){
                 if(ans > j-i+1){
                     ans = j-i+1;
                     x = s.substr(i,j-i+1);
                 }
                
                 if(m.find(s[i]) != m.end()){
                     m[s[i]]++;
                     if(m[s[i]] == 1) count++;
                 }
                 i++;
               }
            }
        
            j++;
        }
        if(x.size() == 0) return "-1";
        return x;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends