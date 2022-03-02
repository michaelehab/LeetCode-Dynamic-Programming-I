class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for(int i = 0;i < nums.size(); i++){
            if(mx < i) return false;
            mx = max(i + nums[i], mx);
        }
        return true;
    }
};