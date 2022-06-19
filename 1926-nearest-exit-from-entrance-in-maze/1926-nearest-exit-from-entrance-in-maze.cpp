// Just Doing BFS And checking level for every boundary indices from given entrance indices and maintaining minimum out of those
class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    bool atboundary(int i , int j , int n , int m)
    {
        return (i==0 || j==0 || i==n-1 || j==m-1);
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[entrance[0]][entrance[1]] = 1;
        int lvl = 0;
        int min1 = INT_MAX;
        while(!q.empty())
        {
            lvl++;
            int sz = q.size();
            while(sz--)
            {
              int x1 = q.front().first;
              int y1 = q.front().second;
              q.pop();
              for(int i = 0 ; i < 4 ; i++)
              {
                  int newx = x1 + dx[i];
                  int newy = y1 + dy[i];
        if(newx < 0 || newy < 0 || newx >=n || newy >=m || maze[newx][newy]=='+' || vis[newx][newy])
                  {
                      continue;
                  }
                  if(atboundary(newx,newy,n,m))
                  {
                      min1 = min(min1 , lvl);
                  }
                  q.push({newx,newy});
                  vis[newx][newy] = 1;
              }
            }
        }
        if(min1==INT_MAX)
        {
            return -1;
        }
        return min1;
    }
};