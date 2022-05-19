class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        
        if(g[0][0] == 1) return 0;
        vector<int> prev(n,0);
        
        for(int i = 0;i<m;i++){
            
            vector<int> temp(n,0);
            
            for(int j = 0;j<n;j++){
                
                if(i == 0 and j == 0) temp[j] = 1;
                else{
                    if(g[i][j] == 1) temp[j] = 0;
                    else{
                        int u = 0;
                        int l = 0;
                        if(i>0)
                            u = prev[j];
                        if(j>0)
                            l = temp[j-1];
                        
                        temp[j] = u + l;
                    }
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
    

};