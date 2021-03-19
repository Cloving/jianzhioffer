/* 第一种: hash*/
class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        set<int> st;
        vector<int> res;
        for (int i = 0; i < array.size(); ++i) {
            if (st.count(array[i])) {
                st.erase(array[i]);
            } else {
                st.insert(array[i]);
            }
        }
        for(auto iter = st.begin(); iter != st.end(); iter++) {
            res.push_back(*iter); 
        }
        return res;
    }
};

/*第二种: 位运算, 未按顺序输出, 能通过leetcode,不能通过牛客 */
class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        int ret = 0;
        for (auto n : array) {
            ret ^= n;
        }
        int div = 1;
        while ((div&ret) == 0) {
            div <<= 1;
        }
        int a = 0, b = 0; 
        for (auto n : array) {
            if ( (div&n) != 0) {
                a ^= n;
            } else {
                b ^= n;
            }
        }
        return vector<int>{a, b};
    }
};