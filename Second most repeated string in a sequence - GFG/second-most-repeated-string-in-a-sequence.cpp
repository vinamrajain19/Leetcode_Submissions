//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int> m;
        for(int i = 0;i<n;i++) m[arr[i]]++;
        
        string ans;
        int f = -1e9;
        int s = -1e9;
        
        priority_queue<pair<int,string>> pq;
        for(auto it : m) pq.push({it.second,it.first});
        
        if(pq.size() == 1) return "";
        
        pq.pop();
        return pq.top().second;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends