//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int n,vector<int> a, vector<int> b) {
        // code here
         long long cnt=0,ans=0,mn=1e9+5;
        int i;
        
        for (i=0; i<n; i++){
            int curr=b[i]/2;
            ans+=(2*curr*a[i]);
            
            if (curr){
               mn=min((int)mn,a[i]);
            }
            
            cnt+=curr;
        }
        
        if (cnt%2){
           ans-=(2*mn); 
        }
        
     return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends