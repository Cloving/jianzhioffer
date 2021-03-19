/* 第一种: 动态规划 */
class Solution {
public:
    int cutRope(int number) {
        vector<int> dp(number+1, 0);
        dp[2] = 1;
        for (int i = 3; i < number+1;i++) {
            for (int j = 2; j < i; ++j) {
                dp[i] = max(dp[i], max(j*(i-j), j* dp[i-j]));
            }
        }
        return dp[number];
    }
};

/* 第二种: 贪心 */


