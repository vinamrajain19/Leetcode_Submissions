//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int find(int s, int d)
    {
        if(s>9)
        {
            return 9;
        }
        else if(s>=1 && s<=9 && d>1)
        {
            return s-1;
        }
        else
        {
            return s;
        }
    }

    string smallestNumber(int S, int D)
    {
        string ans = "";
        while(D!=0)
        {
            int x = find(S, D);
            ans = ans+to_string(x);
            S = S-x;
            D--;
        }

        if(D==0 && S!=0) return "-1";
        reverse(ans.begin(), ans.end());
        return ans;
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