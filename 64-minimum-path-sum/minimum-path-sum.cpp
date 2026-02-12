// class Solution {
// public:
//     int dp[201][201];
//     int n, m;
//     int solve(vector<vector<int>>& grid, int i, int j) {  
//         if (i >= n || j >= m) 
//             return INT_MAX;

//         if (i == n-1 && j == m-1)
//             return grid[i][j];

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         int right = solve(grid, i, j+1);
//         int down  = solve(grid, i+1, j);

//         return dp[i][j] = grid[i][j] + min(right, down);
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         memset(dp, -1, sizeof(dp));
//         n = grid.size();
//         m = grid[0].size();
//         return solve(grid, 0, 0);
//     }
// };
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // base case
        dp[0][0] = grid[0][0];

        // first row (can only come from left)
        for (int j = 1; j < m; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        // first column (can only come from top)
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        // fill rest of dp table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n-1][m-1];
    }
};

