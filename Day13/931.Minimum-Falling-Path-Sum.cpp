class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int> (matrix.back()));
        
        for(int i = n - 2; i >= 0; --i){
            for(int j = 0; j < n; ++j){
                int a = dp[i + 1][j];
                int b = (j + 1 < n) ? dp[i + 1][j + 1] : INT_MAX;
                int c = (j - 1 >= 0) ? dp[i + 1][j - 1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min({a, b, c});
            }
        }
        
        for(int i = 0; i < n; ++i) ans = min(ans, dp[0][i]);
        
        return ans;
    }
};