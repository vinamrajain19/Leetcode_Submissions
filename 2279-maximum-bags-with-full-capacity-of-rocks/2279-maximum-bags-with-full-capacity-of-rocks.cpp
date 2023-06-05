class Solution {
public:
    typedef pair<int, int> pi;
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int a) {
        
        int n = capacity.size();
        int ans = 0;
        int x = a;
        priority_queue<int, vector<int>, greater<int> > q;  

        for(int i = 0;i<n;i++){
             q.push(capacity[i] - rocks[i]);
        }
        
        
        while(q.size() != 0){
            int diff = q.top();
            
            if(diff == 0) ans++;
            else if(diff <= x) {
                x -=  diff;
                ans++;
            }
            else break;
            
            q.pop();
        }
        
        return ans;
    
    }
};