class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int a[128] = {0};
        for (auto i : str) {
            a[i]++;
        }
        for (int i = 0; i < str.size(); ++i) {
            if (a[str[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};