/* 第一种:  */
class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        int a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            int temp = b;
            b = a+b;
            a = temp;
        }
        return b;
    }
};

/* 第二种 */
class Solution {
public:
    int Fibonacci(int n) {
        if (n==0 || n==1) return n;
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
};

/* 第三种 */
class Solution {
public:
    int Fibonacci(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
