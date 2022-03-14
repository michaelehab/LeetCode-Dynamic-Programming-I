class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols));
        ans[0][0] = grid[0][0];
        for(int i = 1; i < cols; i++) ans[0][i] = grid[0][i] + ans[0][i - 1];
        for(int i = 1; i < rows; i++) ans[i][0] = grid[i][0] + ans[i - 1][0];
        
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                ans[i][j] = min(ans[i - 1][j], ans[i][j - 1]) + grid[i][j];
            }
        }
        return ans[rows-1][cols-1];
    }
};