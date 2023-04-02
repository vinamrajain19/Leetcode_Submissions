//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution{
public:

    int t[501][501];
    
    
    bool ispalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int mcm(string &s,int i,int j){
        if(i>=j) return 0;
        
        if(ispalindrome(s,i,j)) return 0;
        
        if(t[i][j] != -1) return t[i][j];
        
        int mn = INT_MAX;
        for(int k = i;k <= j-1;k++){
            int temp = 1 + mcm(s,i,k) + mcm(s,k+1,j);
            mn = min(mn,temp);
        }
        
        return t[i][j] = mn;
    }
    int palindromicPartition(string s)
    {
       
        memset(t,-1,sizeof(t));
         int n = s.size();
        return mcm(s,0,n-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends