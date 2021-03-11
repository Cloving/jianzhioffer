/* 第一种 */
class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0 || number ==1 || number == 2) {
            return number;
        }
        vector<int> dp(number+1, 0);
        dp[1] = 1;
        for (int i = 2; i <= number; ++i) {
            dp[i] = 2*dp[i-1];
        }
        return dp[number];
    }
};


/* 第二种: */
class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0 || number == 1) {
            return number;
        }
        int a = 1, b;
        for (int i = 2; i <= number; ++i) {
            b = a << 1;
            a = b;
        }
        return a;
    }
};


/* 第三种: */
class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0 || number == 1) {
            return number;
        }
        return pow(2, number-1);
    }
};
