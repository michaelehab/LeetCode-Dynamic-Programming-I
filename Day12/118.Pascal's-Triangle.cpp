class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> dp;
        for(int i = 0; i < numRows; ++i){
            vector <int> tmp(i + 1);
            dp.push_back(tmp);
            dp[i][0] = 1;
            dp[i][i] = 1; 
        }
        for(int i = 2; i < numRows; ++i){
            for(int j = 1; j < i; ++j){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        return dp;
    }
};