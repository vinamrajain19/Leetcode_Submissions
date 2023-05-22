class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        
        for(auto it : nums) m[it]++;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(auto it : m){
            pq.push({it.second,it.first});
            if(pq.size() > k) pq.pop();
        }
        
        for(int i = 0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};