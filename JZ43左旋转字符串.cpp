class Solution {
public:
    string LeftRotateString(string str, int n) {
        for (int i = 0; i < n; ++i) {
            str.push_back(str[i]);
        }
        return str.substr(n);
    }
};