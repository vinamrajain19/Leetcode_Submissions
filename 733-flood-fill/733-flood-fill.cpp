class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        queue<pair<int,int>> q;
        
        int color = image[sr][sc];
        q.push({sr,sc});
        
        
        vector<vector<int>> vis(image.size(),vector<int>(image[0].size(),0));
        vis[sr][sc] = 1;
        while(q.size() != 0){
            int n = q.size();
            while(n--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(x > 0 and image[x-1][y] == color and vis[x-1][y] == 0){
                    vis[x-1][y] = 1;
                    image[x-1][y] = newcolor;
                    q.push({x-1,y});
                }
                
                if(y > 0 and image[x][y-1] == color and vis[x][y-1] == 0){
                    vis[x][y-1] = 1;
                    image[x][y-1] = newcolor;
                    q.push({x,y-1});
                }
                
                if(x < image.size() -1 and image[x+1][y] == color and vis[x+1][y] == 0){
                    vis[x+1][y] = 1;
                    image[x+1][y] = newcolor;
                    q.push({x+1,y});
                }
                
                if(y < image[0].size() -1 and image[x][y+1] == color and vis[x][y+1] == 0){
                    vis[x][y+1] = 1;
                    image[x][y+1] = newcolor;
                    q.push({x,y+1});
                }
                
            }
        }
        image[sr][sc] = newcolor;
        return image;
    }
};