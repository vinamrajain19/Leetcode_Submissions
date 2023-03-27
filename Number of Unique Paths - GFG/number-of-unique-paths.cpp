//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<int> curr(b,0);
        vector<int> t(b,0);
        
        for(int i = a-1;i>=0;i--){
            for(int j = b-1;j>=0;j--){
                if(i == a-1 and j == b-1) curr[j] = 1;
                else{
                    int x= 0,y=0;
                    if(i+1 < a){
                        x = t[j];
                    }
                    if(j+1<b) y = curr[j+1];
                    
                    curr[j] = x+y;
                }
            }
            
            t = curr;
        }
        
        return curr[0];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends