class Solution {
public:
    int numIslands(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
            int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(arr[i][j] == '1'){
                     ans++;
                     arr[i][j] = '0';
                     queue<pair<int,int>> q;
                    q.push({i,j});
               
                    while(q.size() != 0){
                       int x = q.front().first;
                       int y = q.front().second;
                       q.pop();
                       
                       if(x > 0 and arr[x-1][y] == '1'){
                            arr[x-1][y] = '0';
                            q.push({x-1,y});
                       }
                
                       if(y > 0 and arr[x][y-1] == '1'){
                            arr[x][y-1] = '0';
                            q.push({x,y-1});
                       }
                       
                       if(x < n-1 and arr[x+1][y] == '1'){
                            arr[x+1][y] = '0';
                            q.push({x+1,y});
                       }
                       
                       if(y < m-1 and arr[x][y+1] == '1'){
                            arr[x][y+1] = '0';
                            q.push({x,y+1});
                       }
                    
               }
           }
       }
   }
    return ans;
    }
    
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == '0'){
            return;
        }
        
        grid[i][j] = '0';
        
        dfs(grid,i-1,j); //up
        dfs(grid,i,j+1); //right
        dfs(grid,i+1,j); //down
        dfs(grid,i,j-1); //left
    }
};