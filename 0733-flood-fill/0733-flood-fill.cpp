class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        
        if(color == image[sr][sc]) return image;
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        int nc = image[sr][sc];
        
        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i = 0;i<4;i++){
                
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 or ny < 0 or nx >= image.size() or ny >= image[0].size() or image[nx][ny] != nc) continue;
                
                image[nx][ny] = color;
                q.push({nx,ny});
            }
        }
        
        image[sr][sc]= color;
        return image;
    }
};