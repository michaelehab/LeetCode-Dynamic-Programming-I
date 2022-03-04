class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0], currMin = nums[0], ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int c1 = currMax * nums[i];
            int c2 = currMin * nums[i];
            currMax = max({nums[i], c1, c2});
            currMin = min({nums[i], c1, c2});
            ans = max(ans, currMax);
        }
        return ans;
    }
};