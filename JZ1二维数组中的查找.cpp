class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        for (int i = 0; i < array.size(); ++i) {
            int left = 0, right = array[0].size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (array[i][mid] == target) {
                    return true;
                } else if (array[i][mid] > target) {
                    right = mid - 1;
                } else if (array[i][mid] < target) {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};