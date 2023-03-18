class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> ans;
        
        int rs = 0;
        int cs = 0;
        int re = m-1;
        int ce = n-1;
        
        int cnt = 0;
        while(cnt < (m*n)){
            
            for(int i = cs;i<=ce;i++){
                ans.push_back(matrix[rs][i]);
                cnt++;
            }
            rs++;
            
            for(int i = rs;i<=re;i++){
                ans.push_back(matrix[i][ce]);
                cnt++;
            }
            ce--;
            
            if(rs > re or cs > ce) break;
            
            for(int i = ce;i>=cs;i--){
                ans.push_back(matrix[re][i]);
                cnt++;
            }
            re--;
            
            for(int i = re;i>=rs;i--){
                ans.push_back(matrix[i][cs]);
                cnt++;
            }
            cs++;
            
        }
        
        return ans;
    }
};