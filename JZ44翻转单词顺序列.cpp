class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty()) return str;
        string temp = "";
        string res = "";
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] != ' ') {
                temp += str[i];
            } else {
                res =  ' ' + temp + res;
                temp.clear();
            }
        }
        if (!temp.empty()) {
            res = temp + res;
        }
        return res;
    }
};