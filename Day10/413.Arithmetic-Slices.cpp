class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        
        int ans = 0, itr = 0;
        int curr = nums[1] - nums[0];
        
        for(int i = 1; i < nums.size() - 1 ; i++){
            int tmp = nums[i + 1] - nums[i];
            if(tmp == curr) itr++;
            else {
                curr = tmp;
                itr = 0;
            }
            ans += itr;
        }
        
        return ans;
    }
};