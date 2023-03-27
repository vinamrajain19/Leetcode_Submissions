class Solution
{
    public:

    int dp[201][201];
    int f(vector<vector < int>> &g, int i, int j)
    {

        if (i == g.size() - 1 and j == g[0].size() - 1) return g[i][j];

        if (i >= g.size() or j >= g[0].size()) return 1e9;

        if (dp[i][j] != -1) return dp[i][j];

        int a = g[i][j] + f(g, i + 1, j);
        int b = g[i][j] + f(g, i, j + 1);

        return dp[i][j] = min(a, b);
    }
    
    int minPathSum(vector<vector < int>> &grid)
    {
        memset(dp, -1, sizeof(dp));
        return f(grid, 0, 0);
    }
};