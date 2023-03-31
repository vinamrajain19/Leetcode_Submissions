//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
    
  public:
  
  int mod = 1e9+7;
  int dp[100001];
    
    int f(string &s,int idx){
        if(idx == s.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        
        vector<int> v(26,0);
        
        int ans = 0;
        for(int i = idx;i<s.size();i++){
            if(v[s[i] - 'a'] == 1) continue;
            
            v[s[i] - 'a'] = 1;
            ans = (ans + 1 + f(s,i+1)) % mod;
        }
        
        return dp[idx] = ans % mod;
    }
    
    int distinctSubseqII(string s) {
        memset(dp,-1,sizeof(dp));
        return f(s,0);
        
    }
    
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    return distinctSubseqII(s) + 1;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends