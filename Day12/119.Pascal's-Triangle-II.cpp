class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector <vector <int>> dp;
        for(int i = 0; i < rowIndex + 1; ++i){
            vector <int> tmp(i + 1);
            dp.push_back(tmp);
            dp[i][0] = 1;
            dp[i][i] = 1; 
        }
        for(int i = 2; i < rowIndex + 1; ++i){
            for(int j = 1; j < i; ++j){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        return dp[rowIndex];
    }
};