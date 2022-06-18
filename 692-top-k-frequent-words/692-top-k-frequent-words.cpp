class Solution {
public:
    static bool comp(pair<int,string> &a,pair<int,string> &b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> m;
        
        for(int  i = 0;i<words.size();i++){
            m[words[i]]++;
        }
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(&comp)> pq(comp);
        for(auto it : m){
            pq.push({it.second,it.first});
            if(pq.size() > k) pq.pop();
        }
        
        vector<string> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
                    
        
    }
};