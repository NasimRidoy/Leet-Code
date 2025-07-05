class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3)
            return n;
        int prev = 3;
        int secondPrev = 2;
        int cur;
        for (int i = 4; i <= n; i++) {//dp approach
            cur = prev + secondPrev; //take 1 step from prev step or, take 2 step from secondPrev
            secondPrev = prev;
            prev = cur;
        }
        return cur;
    }
};