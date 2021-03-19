/* 第一种: */
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        for(int i = 0; i < array.size(); ++i) {
            vector<int>::iterator it = find(array.begin()+i+1, array.end(), sum - array[i]);
            if (it != array.end()) {
                result.push_back(array[i]);
                result.push_back(*it);
                break;
            }
        }
        return result;
    }
};

/* 第二种: 双指针 */
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        int left = 0, right = array.size() - 1;
        while (left < right) {
            if (array[left] + array[right] == sum) {
                result.push_back(array[left]);
                result.push_back(array[right]);
                break;
            } else if (array[left] + array[right] < sum) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};
