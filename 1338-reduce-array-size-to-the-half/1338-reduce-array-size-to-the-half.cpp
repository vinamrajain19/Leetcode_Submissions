class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto it : arr) m[it]++;
        
        priority_queue<pair<int,int>> pq;
        
        for(auto it : m){
            pq.push({it.second,it.first});
        }
        
        int n = arr.size();
        
        int ans = 0;
        
        int x = n;
        while(x > (n/2)){
            int cnt = pq.top().first;
            x -= cnt;
            ans++;
            pq.pop();
        }
        return ans;
    }
};