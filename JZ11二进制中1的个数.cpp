/* 第一种:  */
class Solution {
public:
  int  NumberOf1(int n) {
    if (n == 0) {
      return 0;
    }
    int cnt = 0, mark = 1;
    while (mark != 0) {
      if (n & mark) {
        cnt++;
      }
      mark <<= 1;
    }
    return cnt;
  }
};


/* 第二种:  */
class Solution {
public:
  int  NumberOf1(int n) {
    int res = 0;
    while (n != 0) {
      res++;
      n = n & (n-1);
    }
    return res;
  }
};


