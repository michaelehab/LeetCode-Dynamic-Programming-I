class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int N = nums.size();
        if (N < 2) return N;
        vector <int> up(N), down(N);
        for (int i = 1; i < N; i++) {
            for(int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) up[i] = max(up[i],down[j] + 1);
                else if (nums[i] < nums[j]) down[i] = max(down[i],up[j] + 1);
            }
        }
        return 1 + max(down[N - 1], up[N - 1]);
    }
};