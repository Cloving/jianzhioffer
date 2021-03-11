/* 第一种: */
class Solution {
public:
  vector<int> reOrderArray(vector<int>& array) {
    vector<int> odd;
    for (auto iter = array.begin(); iter != array.end();) {
      if (*iter % 2 == 0) {
        odd.push_back(*iter);
        iter = array.erase(iter);
      } else {
        iter++;
      }
    }
    array.insert(array.end(), odd.begin(), odd.end());
    return array;
  }
};

/* 第二种: 利用插入排序的思想*/
class Solution {
public:
  vector<int> reOrderArray(vector<int>& array) {
    int evenIndex = 0;
    int temp;
    for (int i = 0; i < array.size(); ++i) {
      if (array[i] % 2 == 0) {
        continue;
      } else {
        temp = array[i];
        int k = i;
        while (k > evenIndex) {
          array[k] = array[k-1];
          k--;
        }
        array[evenIndex] = temp;
        evenIndex++;
      }
    }
    return array;
  }
};
