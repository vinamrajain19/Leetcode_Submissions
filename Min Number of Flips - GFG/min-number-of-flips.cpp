//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int ans = 0;
    char ch = '1';
    for(int i = 0;i<S.size();i++){
       if(ch != S[i]) ans++;
       
        if(ch == '1'){
           ch = '0';
       }
       else ch = '1';
        
       
    }
    
    int ans1 = 0;
    ch = '0';
    for(int i = 0;i<S.size();i++){
       if(ch != S[i]) ans1++;
       
       if(ch == '1'){
           ch = '0';
       }
       else ch = '1';
       
    }
    return min(ans,ans1);
}