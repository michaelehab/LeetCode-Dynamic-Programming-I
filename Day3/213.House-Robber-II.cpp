class Solution {
public:
    int solve(vector<int>& nums, int l, int r) {
        int N = r - l + 1;
        if(N == 1) return nums[l];
        
        vector <int> DP(N, 0);
        DP[0] = nums[l];
        DP[1] = max(nums[l], nums[l + 1]);
        
        for(int i = 2; i < N; i++)
            DP[i] = max(nums[l + i] + DP[i - 2], DP[i - 1]);
        
        return DP[N - 1];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(solve(nums, 0, nums.size() - 2), solve(nums, 1, nums.size() - 1));
    }
};