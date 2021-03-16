class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int maxValue = array[0];
        for (int i = 1; i < array.size(); ++i) {
            array[i] += array[i-1] > 0 ? array[i-1] : 0;
            maxValue = max(maxValue, array[i]);
        }
        return maxValue;
    }
};