class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>&dp) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (i > m-1 || j > n-1 || i < 0 || j < 0) return 1e9;
        if (i == m-1) return matrix[i][j];

        if (dp[i][j] != 1e9) return dp[i][j];
                
        int bottom = matrix[i][j] + solve(matrix, i + 1, j, dp);
        int diagLeft = matrix[i][j] + solve(matrix, i + 1, j - 1, dp);
        int diagRight = matrix[i][j] + solve(matrix, i + 1, j + 1, dp);

        return dp[i][j] = min (bottom, min(diagLeft, diagRight));
    }


    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>>dp(m, vector<int>(n, 1e9));

        int mini = INT_MAX;
        for (int x = 0; x < n; x++){
            mini = min (mini, solve(matrix, 0, x, dp));
        }
        return mini;
    }
};