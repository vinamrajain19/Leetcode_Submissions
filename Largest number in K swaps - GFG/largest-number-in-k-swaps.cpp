//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string ans;
    void f(string str,int k,int idx){
        ans = max(ans,str);
        if(idx == str.size() or  k == 0) return;
        
        
        char ch = *max_element(str.begin()+idx+1,str.end());
        
        // two option swap it or not 
        if(ch > str[idx]){
            for(int i = idx+1;i<str.size();i++){
                if(ch == str[i]){
                    swap(str[i],str[idx]);
                    f(str,k-1,idx+1);
                    swap(str[i],str[idx]);
                }
            
            }
        }
        f(str,k,idx+1);
        
    }
    string findMaximumNum(string str, int k)
    {
       ans = str;
       f(str,k,0);
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends