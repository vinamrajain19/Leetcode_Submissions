class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
       priority_queue<int> pq;
        
        for(auto it : piles){
            pq.push(it);
        }
        
        while(k--){
            int t = pq.top();
            pq.pop();
            
            t -= ceil(t/2);
            if(t > 0) pq.push(t);
        }
        
        int ans = 0;
        
        while(pq.size()){
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
    }
    
};