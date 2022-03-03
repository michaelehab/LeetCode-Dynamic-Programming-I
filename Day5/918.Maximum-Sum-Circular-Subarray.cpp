class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, minSum = nums[0], maxSum = nums[0], curMax = 0, curMin = 0;
        // Kadane Algorithm
        for(int n : nums){
            total += n;
            
            curMax = max(n, curMax + n);
            maxSum = max(maxSum, curMax);
            
            curMin = min(n, curMin + n);
            minSum = min(minSum, curMin);
        }
        
        return (maxSum < 0) ? maxSum : max(maxSum, total-minSum);
    }
};