class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1);
        dp[0]=1;
        if(s[0] == '0') dp[1] = 0;
        else dp[1] = 1;
        for(int i = 2; i <= s.size(); i++){
            int take1, take2;
            
            if(s[i - 1] == '0') take1 = 0;
            else take1 = dp[i - 1];
            
            int tmp = (stoi(s.substr(i - 2, 2)));
            if(tmp <= 26 && tmp > 0 && s[i - 2] != '0') take2 = dp[i - 2];
            else take2 = 0;
            
            dp[i] = take1 + take2;
        }
        return dp[s.size()];
    }
};