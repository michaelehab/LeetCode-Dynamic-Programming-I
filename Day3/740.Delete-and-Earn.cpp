class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int N = nums.size();
        if(N == 1) return nums[0];
        
        unordered_map <int, int> occ;
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> DP(mx + 1, 0);
        
        for(int n : nums) occ[n]++;
        
        DP[0] = 0;
        DP[1] = occ[1];
        for(int i = 2; i <= mx; i++)
            DP[i] = max(i*occ[i] + DP[i-2], DP[i - 1]);
        
        return DP[mx];
    }
};