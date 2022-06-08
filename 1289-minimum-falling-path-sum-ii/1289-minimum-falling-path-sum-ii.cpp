class Solution {
public:
    int minFallingPathSumHelper(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(row == grid.size()-1 && col >= 0 && col <= grid[0].size()-1) return grid[row][col];
        if(col < 0 && col >= grid[0].size()) return INT_MAX;
        int curr = grid[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        int currMin = INT_MAX;
        for(int i = 0; i < grid[row].size(); i++) {
            if(i == col) continue;
            currMin = min(currMin, minFallingPathSumHelper(row+1, i, grid, dp));
        }
        currMin += curr;
        return dp[row][col] = currMin;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = INT_MAX;
        for(int i = 0; i < m; i++) {
            ans = min(ans, minFallingPathSumHelper(0, i, grid, dp));
        }
        return ans;
    }
};