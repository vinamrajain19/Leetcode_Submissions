class Solution {
public:
    
    /* Idea:
We need to find the last day where it's possible to pass.
 So we use binary search.
If for day i we can walk from top to bottom, then maybe we can walk also on a later day. So lo = mid + 1.
If we can't walk on day i, then we won't be able to walk on any later day and we have to check earlier days. So hi = mid - 1.
For checking if it's possible to wal k on day i, we will use BFS.
Time Complexity: O(row * col * log(row * col))
Space Complexity: O(row * col) */
    
    
    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};
    
    bool isValidPoint(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    bool f(int row, int col, vector<vector<int>>& cells, int day) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        
        for (int i = 0; i <= day; i++) grid[cells[i][0]-1][cells[i][1]-1] = 1;
        
        queue<pair<int, int>> q;
        
        for (int i = 0; i < col; i++) {
            if (!grid[0][i]) {
                q.push({0, i});
                grid[0][i] = 1;
            }
        }
        
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            
            if (curr.first == row - 1) return true;
            
            for (int i = 0; i < 4; i++) {
                int x = curr.first + dx[i];
                int y = curr.second + dy[i];
                
                if (isValidPoint(x, y, row, col) && !grid[x][y]) {
                    grid[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
        
        return false;
        
    }

    
    int latestDayToCross(int row, int col, vector<vector<int>>& c) {
        int s = 1;
        int e = c.size()-1;
        
        int ans = 0;
        
        while(s <= e){
            
            int m = (s+e)/2;
            
            
            if(f(row,col,c,m)){
               ans = m;
                s = m+1;
            }
            
            else e = m-1;
        }
        
        return ans+1;
    }
};