//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool f(int n,int k,vector<int> &st,int mid){
        int cows = 1;
        
        int last  = st[0];
        
        for(int i = 1;i<n;i++){
            if(st[i] - last >= mid){
                cows++;
                last = st[i];
            }
        }
        
        return cows >= k;
    }

    int solve(int n, int k, vector<int> &st) {
    
        // Write your code here\
        
        sort(begin(st),end(st));
        
        int s = 0;
        
        int e = st[n-1] - st[0];
        
        int ans = -1;
        
        while(s <= e){
            int m = (s+e)/2;
            
            if(f(n,k,st,m)){
                ans = m;
                s = m+1;
            }
            else e = m-1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends