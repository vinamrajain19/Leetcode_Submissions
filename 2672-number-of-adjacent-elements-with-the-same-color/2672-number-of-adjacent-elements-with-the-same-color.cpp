class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        vector<int> c(n);
        int cnt = 0;
        vector<int> ans;
        
        for(auto it : q){
            // check if already same h to sub 
            
            if(c[it[0]]){
                 if(it[0] - 1 >= 0 and  c[it[0]] == c[it[0] -1]){
                    cnt--;
                }
                if(it[0] + 1 < n and c[it[0]] == c[it[0] + 1]){
                    cnt--;
                 }
            }
           
            
            // update color
            c[it[0]] = it[1];
            
            // now update again
            
            if(it[0] - 1 >= 0 and  c[it[0]] == c[it[0] -1]){
                cnt++;
            }
            if(it[0] + 1 < n and c[it[0]] == c[it[0] + 1]){
                cnt++;
            }
            
            ans.push_back(cnt);
            
            
            
        }
        
        return ans;
    }
};