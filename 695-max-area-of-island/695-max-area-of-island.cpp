class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        int mx = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int cnt = 0;
                if(arr[i][j] == 1){
                     arr[i][j] = 0;
                     
                     queue<pair<int,int>> q;
                     q.push({i,j});
               
                    while(q.size() != 0){
                       int x = q.front().first;
                       int y = q.front().second;
                       q.pop();
                       cnt++;
                       
                       if(x > 0 and arr[x-1][y] == 1){
                            
                            arr[x-1][y] = 0;
                            q.push({x-1,y});
                       }
                
                       if(y > 0 and arr[x][y-1] == 1){
                            arr[x][y-1] = 0;    
                            q.push({x,y-1});
                       }
                       
                       if(x < n-1 and arr[x+1][y] == 1){
                           
                            arr[x+1][y] = 0;
                            q.push({x+1,y});
                       }
        
                       if(y < m-1 and arr[x][y+1] == 1){
                            arr[x][y+1] = 0;
                            q.push({x,y+1});
                       }
                       cout<<cnt<<endl;
                    } 
                     
                }
                mx = max(cnt,mx);
                
           }
        }
        return mx;
   }
};