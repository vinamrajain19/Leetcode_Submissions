//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        
        vector<int> dp(nums.size(),1);
        vector<int> hash(nums.size(),1);
        
        
        int mx = -1;
        int lastindex = -1;
        
        for(int i = 0;i<nums.size();i++){
            
            hash[i] = i;
            
            
            for(int j = 0;j<i;j++){
                if((nums[i] % nums[j]) == 0 and (dp[i] < 1 + dp[j])){
                    dp[i] = 1 + dp[j];
                    //cout<<nums[j]<<" ";
                    hash[i] = j;
                 }
            }
            
            //cout<<temp.size() <<" ";
            
            if(dp[i] > mx){
                //ans = temp;
                mx = dp[i];
                lastindex = i;
            }
        }
        
        ans.push_back(nums[lastindex]);
        
         while(hash[lastindex] != lastindex){ // till not reach the initialization value
            lastindex = hash[lastindex];
            ans.push_back(nums[lastindex]);    
         }
        
        return ans;
    }
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
        return largestDivisibleSubset(arr);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends