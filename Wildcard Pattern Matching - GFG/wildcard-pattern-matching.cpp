//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool isMatch(string s, string p) {
        vector<bool> prev(p.size()+1,0);
        vector<bool> curr(p.size()+1,0);
        
        prev[0] = 1;
        
        
        for(int j = 1;j<=p.size();j++){
            if(p[j-1] == '*')
                prev[j] = prev[j-1];
        }
        
        
        for(int i = 1;i<=s.size();i++){
            for(int j = 1;j<=p.size();j++){
                
                if(s[i-1] == p[j-1] or p[j-1] == '?'){
                    curr[j] = prev[j-1];
                }
                
                else if(p[j-1] == '*'){
                    curr[j] = prev[j] or curr[j-1];
                }
                else{
                    curr[j] = 0;
                }
            }
            
            prev = curr;
        }
        
        
        return prev[p.size()];
        
        
    }
    int wildCard(string pattern,string str)
    {
        return isMatch(str,pattern);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends