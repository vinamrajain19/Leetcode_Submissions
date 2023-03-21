//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int smallestdivisor(vector<int>& nums, int th) {
        int s = 1;
        int e = *max_element(nums.begin(),nums.end());
        
        int ans = 0;
        
        while(s <= e){
            int m = (s+e)/2;
            int cnt = 0;
            
            for(auto it : nums){
                cnt += ceil(it * 1.0 /m);
            }
            
            if(cnt <= th){
                ans = m;
                e = m-1;
            }
            else s = m+1;
            
        }
        
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        return smallestdivisor(nums,K);
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
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends