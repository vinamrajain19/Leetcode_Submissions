class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
      //  vector<vector<int>> dp(n,vector<int>(n,-1));
        // call for every element in last row and find min of all because it is a variable starting pt and variable ending pt problem
        
        vector<int> prev(n,0);
        
        //initialsation
        for(int i = 0;i<n;i++){
            prev[i] = matrix[0][i];
        }
        for(int i = 1;i<n;i++){
            vector<int> temp(n,0);
            for(int j = 0;j<n;j++){
                int u = matrix[i][j] + prev[j];
                
                int ld = matrix[i][j];
                if(j-1 >= 0) ld += prev[j-1];
                else ld = 1e9;
                
                int rd = matrix[i][j];
                if(j+1 < n) rd += prev[j+1];
                else rd = 1e9;
                
                temp[j] = min(u,min(ld,rd));
            }
            prev = temp;
        }
        
        int ans = 1e9;
        for(int i = 0;i<n;i++){
            ans = min(ans,prev[i]);
        }
        
        return ans;
    }
};