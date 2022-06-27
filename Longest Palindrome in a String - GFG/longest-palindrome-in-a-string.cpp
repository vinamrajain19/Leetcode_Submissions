// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
         vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        // len = j-i+1
        int start = 0;
        int len = 0;
        for(int g = 0;g<s.size();g++){
            for(int i = 0 ,j = g ; j<s.size(); i++, j++){
                if(g == 0){
                    dp[i][j] = 1;
                    if(j-i+1 > len){
                        start = i;
                        len = j-i+1;
                    }
                }
                else if(g == 1 and s[i] == s[j]){
                    dp[i][j] = 1;
                    if(j-i+1 > len){
                        start = i;
                        len = j-i+1;
                    }
                }
                else if(s[i] == s[j] and dp[i+1][j-1] == 1){
                    dp[i][j] = 1;
                    if(j-i+1 > len){
                        start = i;
                        len = j-i+1;
                    }
                    
                }
            }
        }
        return s.substr(start,len);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends