class Solution {
public:
    int nthUglyNumber(int n) {
        vector <int> dp(n + 1);
        dp[1] = 1;
        int ptr_2 = 1, ptr_3 = 1, ptr_5 = 1;
        for(int i = 2; i <= n; ++i){
            dp[i] = min({dp[ptr_2] * 2, dp[ptr_3] * 3, dp[ptr_5] * 5});
            if(dp[i] == dp[ptr_2] * 2) ++ptr_2;
            if(dp[i] == dp[ptr_3] * 3) ++ptr_3;
            if(dp[i] == dp[ptr_5] * 5) ++ptr_5;
        }
        return dp[n];
    }
};