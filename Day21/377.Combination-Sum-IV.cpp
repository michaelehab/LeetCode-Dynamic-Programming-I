class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector <long long> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; ++i){
            for(int n : nums){
                if(i - n >= 0){
                    dp[i] += dp[i - n];
                    if(dp[i] > INT_MAX) break;
                }
            }
        }
        return dp[target];
    }
};