class Solution {
public:
    
    double dfs(int n, int k, int r, int c, vector<vector<int>> dirs, vector<vector<vector<double>>>& dp) {
        if (r < 0 || r >= n || c < 0 || c >= n) return 0;
        if (k == 0) return 1;
        if (dp[r][c][k] != -1) return dp[r][c][k];
        double ans = 0;
        for (int i = 0; i < 8; ++i) {
            ans += 0.125 * dfs(n, k - 1, r + dirs[i][0], c + dirs[i][1], dirs, dp);
        }

        return dp[r][c][k] = ans;
    }
    
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};
        return dfs(n, k, row, column, dirs, dp);
    }
};