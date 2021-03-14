class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int top = 0, left = 0, right = col - 1, bottom = row - 1;
        vector<int> res;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }
            for (int j = top + 1; j <= bottom; ++j) {
                res.push_back(matrix[j][right]);
            }
            if (top !=  bottom) {
                for (int i = right - 1; i >= left; --i) {
                    res.push_back(matrix[bottom][i]);
                }
            }
            if (left != right) {
                for (int j = bottom - 1; j > top; --j) {
                    res.push_back(matrix[j][left]);
                }
            }
            top++;
            bottom--;
            left++;
            right--;
        }
        return res;
    }
};