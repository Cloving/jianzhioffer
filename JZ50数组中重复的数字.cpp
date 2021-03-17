class Solution {
public:
    int duplicate(vector<int>& numbers) {
        int len = numbers.size();
        if (len == 0) return -1;
        vector<int> vec(len, 0);
        for (int i = 0; i < len; ++i) {
            if (vec[numbers[i]] == 0) {
                vec[numbers[i]]++;
            } else {
                return numbers[i];
            }
        }
        return -1;
    }
};