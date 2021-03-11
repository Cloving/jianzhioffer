/* 第一种: 动态规划 */
class Solution {
public:
    int jumpFloor(int number) {
        vector<int> dp(number + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        if (number == 1 || number == 2) {
            return number;
        }
        for (int i = 3; i <= number; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[number];
    }
};

/* 第二种: 递归 */
class Solution {
public:
    int jumpFloor(int number) {
        if (number == 1 || number == 2) {
            return number;
        }
        return jumpFloor(number - 1) + jumpFloor(number - 2);
    }
};
