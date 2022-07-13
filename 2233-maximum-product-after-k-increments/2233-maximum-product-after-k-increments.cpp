class Solution {
public:
    int mod = 1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto it : nums) pq.push(it);
        
        while(k--){
            int t = pq.top();
            pq.pop();
            pq.push(t+1);
        }
        long long ans = 1;
        while(pq.size() != 0){
            ans = (ans * pq.top()) % mod;
            pq.pop();
        }
        return ans % mod;
    }
};