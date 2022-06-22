class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        
        vector<int> ans;
        vector<pair<int,int>> p;
        while(k--){
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            p.push_back({idx,val});
        }
        sort(p.begin(),p.end());
        for(int i = 0;i<p.size();i++){
            ans.push_back(p[i].second);
        }
        return ans;
        
    }
};