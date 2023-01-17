// If sum(nums[]) < (2 * k) then, we can't make the partition.
 // Now, calculating the partitions in which sum of both sequences is greater than k will take more space  // i.e., DP[sizeof nums][total sum of elements].

// Thus, we can find the sequences whose sum is less than k and the final answer will be all sequences of // nums[] - sequences with sum < k. This is possible because in the 1st step we made ensure that sum(nums[]) // >= (2 * k) which means that if one sequence of partition has sum less than k, other would have sum greater // than k. Here less space is required i.e., Dp[sizeof nums][k + 1].





class Solution {
public:
    typedef long long ll;
    const int mod = 1E9 + 7;
    ll total = 0;
    vector<vector<int>> dp;
    
    ll cal(int i, ll sum, vector<int>& nums, int k) {
        if(sum > k) {
            return 0;
        }
        if(i == nums.size()) {
            return sum < k ? 1 : 0;
        }
        if(dp[i][sum] != -1)
            return dp[i][sum];
        ll take = cal(i + 1, sum + nums[i], nums, k) % mod;
        ll nake = cal(i + 1, sum, nums, k) % mod;
        return dp[i][sum] = (take + nake) % mod;
    }
    
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        for(auto it : nums)
            total += it;
        if(total < (2 * k))
            return 0;
        
        dp = vector<vector<int>> (n, vector<int> (k + 1, -1));
        ll x = cal(0, 0, nums, k);
        x--;           // x also include count of empty sequence i.e., {}
        ll y = 2;      // Total number of sequences
        
        for(int i = 2; i <= n; i++) {
            y *= 2; y %= mod;
        }
        
        y -= 2;        // Subtracting sequences whose partition is not possible i.e., {} and {all elements of nums[]}
        
        ll ans = ((y - ((2 * x) % mod)) + mod) % mod;
        
        return ans;
    }
};