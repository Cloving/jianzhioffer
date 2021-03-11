/* 第一种: */
class Solution {
public:
    double Power(double base, int exponent) {
        return pow(base, exponent);
    }
};


/* 第二种: 暴力法 */

class Solution {
public:
  double Power(double b, int n) {
    if (n < 0) {
      b = 1 / b;
      n = -n;
    }
    double ret = 1.0;
    for (int i=0; i<n; ++i) ret *= b;
    return ret;
  }
};
