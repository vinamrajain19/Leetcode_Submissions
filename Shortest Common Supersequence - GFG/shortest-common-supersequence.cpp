//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int lcs(string text1,string text2){
        
    
    int m = text1.size();
        int n = text2.size();
        int t[m+1][n+1];
        //initialisation 
        for(int i= 0;i<m+1;i++){
            for(int j = 0;j<n+1;j++){
                if(i==0 or j==0) t[i][j] = 0;
            }
        }
        
        //main code
        for(int i = 1;i<m+1;i++){
            for(int j= 1;j<n+1;j++){
                if(text1[i-1] == text2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return t[m][n];
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        int LCS = lcs(X,Y);
        return m+n - LCS;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends