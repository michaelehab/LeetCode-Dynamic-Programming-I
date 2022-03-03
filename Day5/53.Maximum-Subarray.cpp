class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane Algorithm
        int sum = nums[0], max_sum = sum;
        for(int i = 1; i < nums.size(); i++){
            sum = max(sum + nums[i], nums[i]);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};