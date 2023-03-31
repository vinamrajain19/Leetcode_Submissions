//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
   int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        
       // vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        
        vector<int> prev(n2+1,0);
        vector<int> curr (n2+1,0);
        

        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1] == text2[j-1])
                    curr[j] = 1+prev[j-1];
                else
                    curr[j]= max(prev[j], curr[j-1]);

            }
            
            prev = curr;
        }
        return curr[n2];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        
        return longestCommonSubsequence(s,t);
    }
  
  
  
    int longestPalinSubseq(string A) {
        //code here
        return longestPalindromeSubseq(A);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends