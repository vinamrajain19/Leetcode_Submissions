//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        string s = "";
        long long st = pow(10,D-1);
        long long e = pow(10,D)-1;
        for(long long i =st;i<=e;i++){
            
            string x = to_string(i);
            int sum = 0;
            for(int j=0;j<x.size();j++){
                sum += (x[j] - '0');
            }
            
            if(sum == S) return x;
        }
        
        
        return "-1";
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends