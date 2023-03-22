//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        
        int i = 0;
        int j = 0;
        
        int ans = 0;
        
        int cnt = 0;
        
        int x = 0;
        
        while(j < nums.size()){
            
            if(nums[j] % 2 != 0){
                cnt++;
                x = 0;
            }
            
            while(cnt == k){
                x++;
                if(nums[i++] % 2 == 1){
                    cnt--;
                }
            }
            
            ans += x;
            j++;
        } 
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends