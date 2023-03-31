//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	 
	int lcs(string text1, string text2) {
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
	int minOperations(string str1, string str2) 
	{ 
	    int LCS = lcs(str1,str2);
	    int insertion  = str2.size() - LCS;
	    int deletion = str1.size() - LCS;
	    
	    return insertion  + deletion;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends