class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rs = 0;
        int re = matrix.size()-1;
        int cs = 0;
        int ce = matrix[0].size()-1;
        
        while(rs<=re and cs<=ce){
            //right
            for(int i = cs;i<=ce;i++){
                ans.push_back(matrix[rs][i]);
            }
            rs++;
            
            //down
            for(int i = rs;i<=re;i++){
                ans.push_back(matrix[i][ce]);
            }
            ce--;
            
            if(rs>re || cs>ce) break;
            
            //left
            for(int i = ce;i>=cs;i--){
                ans.push_back(matrix[re][i]);
            }
            re--;
            
            //up
            for(int i = re;i>=rs;i--){
                ans.push_back(matrix[i][cs]);
            }
            cs++;
            
        }
        return ans;
    }
};