/* 第一种:  */
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.empty()) return false;
        sort(numbers.begin(), numbers.end());
        int nonZeroIdx = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            if (numbers[i] == 0) {
                nonZeroIdx++;
            } else {
                if (i+1 < numbers.size() && numbers[i] == numbers[i+1]) {
                    return false;
                }
            }
        }
        return numbers.back() - numbers[nonZeroIdx] < 5;
    }
};

/* 第二种:  */
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.empty()) return false;
        set<int> st;
        int maxValue = 0, minValue = 14;
        for (auto n : numbers) {
            if (n > 0) {
                if (st.count(n)) {
                    return false;
                } else {
                    st.insert(n);
                }
                maxValue = max(maxValue, n);
                minValue = min(minValue, n);
            }
        }
        return maxValue - minValue < 5;
    }
};
