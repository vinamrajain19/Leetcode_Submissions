class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    
        priority_queue<int> q(stones.begin(),stones.end());
        
        while(q.size()>1){
         
            int max1 = q.top();
            q.pop();
            int max2 = q.top();
            q.pop();
            if(max1 != max2) {           
                q.push(max1-max2);
            }
        }
        return q.size() == 0 ? 0 : q.top();
    }
};
