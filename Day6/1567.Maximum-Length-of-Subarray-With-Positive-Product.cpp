class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans;
        vector <int> pve_product(nums.size(), 0);
        vector <int> nve_product(nums.size(), 0);
        if(nums[0] > 0){
            pve_product[0] = 1;
            ans = 1;
        }
        else if(nums[0] < 0){
            nve_product[0] = 1;
            ans = 0;
        }
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > 0){
                pve_product[i] = pve_product[i - 1] + 1;
                if(nve_product[i - 1]) nve_product[i] = nve_product[i - 1] + 1;
            }
            else if(nums[i] < 0){
                nve_product[i] = pve_product[i - 1] + 1;
                if(nve_product[i - 1]) pve_product[i] = nve_product[i - 1] + 1;
            }
            ans = max(ans, pve_product[i]);
        }
        return ans;
    }
};