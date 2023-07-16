class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> m;
        for(auto it : s) m[it]++;
        
        priority_queue<pair<int,int>> pq;
        
        for(auto it : m){
            pq.push({it.second,it.first});
        }
        
        string ans= "";
        
        while(pq.size() > 1){
            char c1 = pq.top().second;
            int cnt1 = pq.top().first;
            pq.pop();
            
            char c2 = pq.top().second;
            int cnt2 = pq.top().first;
            pq.pop();
            
            
            ans += c1;
            ans += c2;
            
            cnt1--;
            cnt2--;
            
            if(cnt1 > 0) pq.push({cnt1,c1});
            if(cnt2 > 0) pq.push({cnt2,c2});
            
            
        }
        
        if(pq.size() and pq.top().first > 1) return "";
        else if(pq.size()) ans += pq.top().second;
        return ans;
    }
};