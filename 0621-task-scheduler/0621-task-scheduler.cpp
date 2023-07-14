class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> m;
        
        for(auto it : tasks) m[it]++;
        
        priority_queue<int> pq;
        
        for(auto it : m) pq.push(it.second);
        
        int ans = 0;
        
        while(pq.size()){
            
            vector<int> temp;
            for(int i = 0;i<=n;i++){
                if(pq.size() > 0){
                temp.push_back(pq.top());
                pq.pop();
                }
            }
            
            for(int i = 0;i<temp.size();i++){
                temp[i]--;
                if(temp[i] > 0) pq.push(temp[i]);
            }
            
            if(pq.size() == 0) ans += temp.size();
            else ans += n+1;
            
        }
        
        return ans;
    }
};