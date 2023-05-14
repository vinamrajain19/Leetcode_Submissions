class Solution {
public:
  
    int f(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp) {
            int m = grid.size();
            int n = grid[0].size();

            if (dp[row][col] != 0) {
                return dp[row][col];
            }

            int ans = 0;

            // Explore the three possible moves
            if (row > 0 && col < n - 1 && grid[row][col] < grid[row - 1][col + 1]) {
                ans = max(ans, 1 + f(grid, row - 1, col + 1, dp));
            }
            if (col < n - 1 && grid[row][col] < grid[row][col + 1]) {
                ans = max(ans, 1 + f(grid, row, col + 1, dp));
            }
            if (row < m - 1 && col < n - 1 && grid[row][col] < grid[row + 1][col + 1]) {
                ans = max(ans, 1 + f(grid, row + 1, col + 1, dp));
            }

            dp[row][col] = ans;
            return ans;
    }

    int maximumMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int ans = 0;


        for (int i = 0; i < m; i++) {
            ans = max(ans, f(grid, i, 0, dp));
        }

        return ans;
    }

    
    int maxMoves(vector<vector<int>>& grid) {
       return maximumMoves(grid);
    }
};