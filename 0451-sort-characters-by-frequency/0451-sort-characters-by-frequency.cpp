class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto it : s) m[it]++;
        
        priority_queue<pair<int,char>> pq;
        
        for(auto it : m) pq.push({it.second,it.first});
        
        string ans= "";
        while(pq.size()){
            char ch = pq.top().second;
            int cnt = pq.top().first;
            
            while(cnt--) ans+=ch;
            pq.pop();
        }
        return ans;
    }
};