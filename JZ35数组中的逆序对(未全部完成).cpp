/* 第一种: 暴力破解 */

class Solution {
public:
    int InversePairs(vector<int> data) {
        long res = 0;
        for (int j = data.size() - 1; j >= 0; --j) {
            for (int i = 0; i < j; ++i) {
                if (data[i] > data[j]) {
                    res++;
                }
            }
        }
        return res % 1000000007;
    }
};

/* 第二种: 归并排序 */

