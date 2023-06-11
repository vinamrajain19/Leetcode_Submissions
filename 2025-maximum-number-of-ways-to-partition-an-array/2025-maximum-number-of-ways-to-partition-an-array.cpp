/* How can we find the count of pivots, if we are not allowed to change any value?
We can iterate over prefixSum array, and count all indexes where pref[i] == suff[i+1].
Now suppose we are allowed to change an element, say nums[j] to value K. How will it change the array prefixSum and suffixSum?
Let d be the increase in jth element => d = K - nums[j]
We can easily see, all values from pref[ j ] to pref[n-1] will also increase by d, and all values from suff[ j ] to suff[ 0 ], will also increase by d.
So, if we had the count of all indexes i, such that:
if i < j, then pref[ i ] - suff[ i + 1] = d, in original array i.e. without changing j's value

Because, suffix sum from 0 to j is increased by d.
Thus this difference will now become 0.
Hence, i will become a pivot point.
if i >= j, then pref [ i ] - suff[ i+1 ] = -d, in original array i.e. without changing j's value

Because, prefix sum from j to n-1 is increased by d.
Thus this difference will now become 0.
Hence, i will become a pivot point. */



class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n), suff(n);

        //store prefix and suffix sum
        pref[0] = nums[0]; suff[n-1] = nums[n-1];
        for(int i=1; i<n; ++i) { 
            pref[i]     = pref[i-1] + nums[i]; 
            suff[n-1-i] = suff[n-i] + nums[n-1-i];
        } 
        // for(int i=n-2; i>=0; --i) suff[i] = suff[i+1] + nums[i];
 
        long long ans = 0;
        unordered_map<long long,long long> left, right;
        
        //intially store the differences in the hashmap right
        for(int i=0;i<n-1; ++i) right[pref[i] - suff[i+1]]++;
        
        
        if(right.count(0)) ans = right[0];
        for(int i=0; i<n; ++i){

            //find the number of pivot indexes when nums[i] is changed to k
            long long curr = 0, diff = k-nums[i];
            if(left.count(diff)) curr+=left[diff];
            if(right.count(-diff)) curr+=right[-diff];

            //update answer
            ans = max(ans, curr);
            
            //transfer the current element from right to left
            if(i<n-1){
                long long dd = pref[i]-suff[i+1]; 
                left[dd]++; right[dd]--;
                if(right[dd] == 0) right.erase(dd);

            }
        }
        return ans;
    }
};