class Solution {
public:
    int minCost(string c, vector<int>& n) {
        
        stack<pair<char,int>> s;
        int ans = 0;
        
        for(int i = 0;i<c.size();i++){
            
            if(s.size() > 0 and s.top().first == c[i]){
                if(s.top().second <= n[i]){
                    ans += s.top().second;
                    s.pop();
                    s.push({c[i],n[i]});
                }
                else{
                    ans += n[i];
                }
            }
            else{
                s.push({c[i],n[i]});
            }
            
        }
        return ans;
        
    }
};