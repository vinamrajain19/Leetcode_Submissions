class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int rs = 0;
        int re = n-1;
        int cs = 0;
        int ce = n-1;
        
        int cnt = 1;
        
        while(rs<=re and cs<=ce){
            //right
            for(int i = cs;i<=ce;i++){
                ans[rs][i] = cnt++;
            }
            rs++;
            
            //down
            for(int i = rs;i<=re;i++){
                ans[i][ce] = cnt++;
            }
            ce--;
            
            if(rs>re || cs>ce) break;
            
            //left
            for(int i = ce;i>=cs;i--){
                ans[re][i] = cnt++;
            }
            re--;
            
            //up
            for(int i = re;i>=rs;i--){
                ans[i][cs] = cnt++;
            }
            cs++;
            
        }
        return ans;
    }
};