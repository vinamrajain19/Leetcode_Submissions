// rows -> number of rows visited 
// cols->number of columns visited
// row X cols intersection can change the values 
// for row : r columns can change r times val of row , so just we count till now: how many number of col visited that affects the values in row (intially n values in that row)
// same for column 
// visited array to maintain the index of rows/column visited to avoid the repeated replacement of same column /row
// only last replacement of particular row/column matters! and give contribution to sum
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) 
    {
        long long ans=0;
        int row=0;
        int col=0;
        vector<bool> visrow(n,0),viscol(n,0);
        
        for(int i=q.size()-1;i>=0;i--)
        {
            int type=q[i][0];
            int val=q[i][2];
            if(type==0)
            {
                int rowind=q[i][1];
                if(visrow[rowind]==0)
                {
                ans+=1LL*val*(n-col);
                row++;
                    visrow[rowind]=1;
                }
                
            }
            else
            {
                
                int colind=q[i][1];
                if(viscol[colind]==0)
                {
                    ans+=1LL*val*(n-row);
                col++;
                    viscol[colind]=1;
                }
                
            }
            
        }
        return ans;
    }
};