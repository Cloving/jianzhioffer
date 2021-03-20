/* 第一种: */
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        if (num.size() < 0 || size < 1 || size > num.size()) return res;
        for (int i = 0; i + size - 1 < num.size(); ++i) {
            int j = i + size - 1;
            int maxValue = num[i];
            for (int k = i+1; k <= j; ++k) {
                maxValue = max(maxValue, num[k]);
            }
            res.push_back(maxValue);
        }
        return res;
    }
};

/* 第二种: */
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        if (num.size() == 0 || size < 1 || num.size() < size) return res;
        deque<int> dq;
        for (int i = 0; i < num.size(); ++i) {
            while (!dq.empty() && num[dq.back()] < num[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() + size <= i) {
                dq.pop_front();
            }
            if (i + 1 >= size) {
                res.push_back(num[dq.front()]);
            }
        }
        return res;
    }
};


