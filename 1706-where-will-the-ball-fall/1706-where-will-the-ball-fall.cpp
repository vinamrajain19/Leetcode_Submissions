class Solution {
public:

   
 vector<int> findBall(vector<vector<int>>& mat) {
       int n = mat.size() , m = mat[0].size();
       vector<int> ans(m,-1);
    
        for(int j = 0; j < m; j++){
        
        int r = 0, c = j;
        while(r < n){
            if(mat[r][c] == 1){
                if(c == m-1 || mat[r][c+1] == -1)
                    break;
                else {
                    r++;  c++;
                }
            }
            else{
                if(c == 0 || mat[r][c-1] == 1)
                    break;
                else {
                    r++;  c--;
                }
            }
        }
            
        if(r == n) ans[j] = c;
     }
    
     return ans;
 }
};