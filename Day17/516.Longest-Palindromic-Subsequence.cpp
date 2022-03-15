// Top down (Recursion)
class Solution {
public:
    int memo[1000][1000];
    int dp(const string& s, int l, int r) {
        if (l > r) return 0;
        if (l == r) return 1;
        if (memo[l][r] != 0) return memo[l][r];
        if (s[l] == s[r]) return memo[l][r] = dp(s, l+1, r-1) + 2;
        return memo[l][r] = max(dp(s, l+1, r), dp(s, l, r-1));
    }
    int longestPalindromeSubseq(const string& s) {
        return dp(s, 0, s.size() - 1);
    }
};

// Bottom Up (Iterative)
class Solution {
public:
    int longestPalindromeSubseq(const string& s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; ++j) {
                if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};