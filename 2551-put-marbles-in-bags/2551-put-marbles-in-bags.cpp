class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<int> pqMin;
        priority_queue<int, vector<int>, greater<int>> pqMax;
        
        for(int i = 1; i < weights.size(); ++i){
            pqMax.push(weights[i] + weights[i-1]);
            
            pqMin.push(weights[i] + weights[i-1]);
            
            if(pqMax.size() >= k) { pqMax.pop(); pqMin.pop(); }
        }
        
        long long ans = 0;
        
        while(pqMax.size() > 0){
            ans += pqMax.top() - pqMin.top();
            pqMax.pop(); pqMin.pop();
        }
        
        return ans;
    }
};