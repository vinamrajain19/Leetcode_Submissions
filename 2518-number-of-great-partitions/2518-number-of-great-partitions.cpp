// Basic idea is counting subsets with sum>= k but since nums[i]<=1e9 that will take too much time. Since we know k<=1000 we can count subsets with sum<=k.

//Counting subsets with both partitions having sum>=k is equivalent to counting subsets with ONE OF THE PARTITION with sum<k and subtracting it from total number of subsets(2^n).


class Solution {
    using ll = long long;
    const ll MOD = 1e9 + 7;

    // Basic Knapsack -> Counts subsets with sum less than k
    ll part(ll ind, vector<int>& nums, ll sum, int k, vector<vector<ll>>& dp) {
        if (sum >= k) return 0;
        if (ind == nums.size()) return 1;
        if (dp[ind][sum] != -1) return dp[ind][sum];

        ll take = part(ind + 1, nums, sum + nums[ind], k, dp);
        ll notTake = part(ind + 1, nums, sum, k, dp);

        return dp[ind][sum] = (take % MOD + notTake % MOD) % MOD;
    }

public:
    int countPartitions(vector<int>& nums, int k) {
        ll n = nums.size();

        // Checking if the sum of array > 2 * k,
        // array can never be partitioned if sum is less than 2 * k
        ll sum = accumulate(begin(nums), end(nums), 0LL);
        if (sum < 2 * k) return 0;

        vector<vector<ll>> dp(n, vector<ll>(k + 1, -1));

        // Calculating total number of subsets i.e. 2^n
        ll totalSubsets = 1;
        for (int i = 1; i <= n; i++) {
            totalSubsets = (totalSubsets * 2) % MOD;
        }

        // After calculating the number of partitions with a sum less than k,
        // the solution multiplies the result by 2 to account for the fact
        // that the same partition can be counted as either the left group or
        // the right group.

        // For example, ([1,2,3],[4]) & ([4],[1,2,3]) should be counted separately
        // BUT the part function only considers ([4],[1,2,3])
        
        ll validSubsets = (totalSubsets - 2 * part(0, nums, 0, k, dp) + MOD) % MOD;
        return validSubsets;
    }
};
