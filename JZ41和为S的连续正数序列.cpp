/* 第一种: 暴力穷举 */
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        vector<int> temp;
        for (int i = 1; i <= sum / 2; ++i) {
            int value = i;
            temp.push_back(i);
            for (int j = i+1; j <= (sum / 2)+1; ++j) {
                value += j;
                temp.push_back(j);
                if (value == sum) {
                    res.push_back(temp);
                    temp.clear();
                    break;
                } else if (value > sum) {
                    temp.clear();
                }
            }
        }
        return res;
    }
};

/* 第二种: 滑动窗口 */
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        int left = 1, right = 2;
        while (right <= (sum/2) + 1) {
            int value = (left + right) * (right-left+1) / 2;
            if (value < sum) {
                right++;
            } else if (value > sum) {
                left++;
            } else {
                vector<int> temp;
                for (int i = left; i <= right; ++i) {
                    temp.push_back(i);
                }
                res.push_back(temp);
                right++;
                left += 2;
            }
        }
        return res;
    }
};