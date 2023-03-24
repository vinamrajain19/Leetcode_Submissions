//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int candy(vector<int>& r) {
        int n = r.size();
       vector<int> l(n,1);
        
        for(int i = 1;i<n;i++){
            if(r[i] > r[i-1]){
                l[i] = l[i-1] + 1;
            }
        }
        
        vector<int> ri(n,1);
        
        for(int i = n-2;i>=0;i--){
            if(r[i] > r[i+1]){
                ri[i] = ri[i+1] + 1;
            }
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans += max(l[i],ri[i]);
        }
        
        return ans;
  }
    int minCandy(int N, vector<int> &ratings) {
        // code here
        return candy(ratings);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends