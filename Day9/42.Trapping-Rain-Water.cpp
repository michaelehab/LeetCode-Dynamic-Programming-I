class Solution {
public:
    int trap(vector<int>& h) {
        if (!h.size()) return 0;
        int N = h.size(), currMax = -1, res = 0;
        vector <int> dp(N);
        
        for (int i = 0; i < N; ++i) {
            currMax = max(currMax, h[i]);
            dp[i] = currMax - h[i];
        }
        
        currMax = -1;
        for (int i = N - 1; i > -1; --i) {
            currMax = max(currMax, h[i]);
            res += min(dp[i], currMax - h[i]);
        }
        return res;
    }
};