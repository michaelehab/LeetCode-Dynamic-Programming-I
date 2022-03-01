class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;

        int a = 1, b = 1;
        for(int i = 2; i <= n; i++){
            int tmp = b;
            b += a;
            a = tmp;
        }
        
        return b;
    }
};