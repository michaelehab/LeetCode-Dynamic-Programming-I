class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int N = values.size(), Max = INT_MIN, ans = INT_MIN;
        vector <int> max_right(N);
        max_right[N - 1] = values[N - 1] - N + 1;
        Max = max_right[N - 1];
        for(int i = N - 2; i >= 0; i--){
            max_right[i] = Max;
            Max = max(Max, values[i] - i);
        }
        
        for(int i = 0; i < N - 1; i++) ans = max(ans, values[i] + i + max_right[i]);
        return ans;
    }
};