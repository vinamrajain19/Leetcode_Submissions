class Solution {
public:
    int islandPerimeter(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        int mx = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(arr[i][j] == 1){
                    int x = i;
                    int y = j;
                    int c = 4;
                      if(x > 0 and arr[x-1][y] == 1){
                            c--;
                       }
                
                       if(y > 0 and arr[x][y-1] == 1){
                           c--;
                       }
                       
                       if(x < n-1 and arr[x+1][y] == 1){
                           c--;
                       }
        
                       if(y < m-1 and arr[x][y+1] == 1){
                           c--;
                       }
                       mx+=c;
                }
           }
        }
        return mx;
    }
};