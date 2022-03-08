class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        int N = s.size();
        vector<bool> dp(N + 1, false);
        dp[0] = true;
        for (int i = 1; i <= N; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j] && word_set.find(s.substr(j, i - j)) != word_set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};