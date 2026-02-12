class Solution {
public:
    int dp[201][201];
    int n, m;
    int solve(vector<vector<int>>& grid, int i, int j) {  
        if (i >= n || j >= m) 
            return INT_MAX;

        if (i == n-1 && j == m-1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(grid, i, j+1);
        int down  = solve(grid, i+1, j);

        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        n = grid.size();
        m = grid[0].size();
        return solve(grid, 0, 0);
    }
};
