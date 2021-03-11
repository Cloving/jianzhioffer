/* 第一种: */
class Solution {
public:
  string replaceSpace(string s) {
    string res = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            res += s[i];
        } else {
            res += "%20";
        }
    }
    return res;
  }
};

/*  第二种:  */
class Solution {
public:   
    string replaceSpace(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                s.replace(i, 1, "%20");
            }
        }
        return s;
    }
};


/*  第三种  */
class Solution {
public:   
    string replaceSpace(string s) {
        string str = "%20";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                s = s.substr(0, i) + str + s.substr(i+1);
                i += 2;
            }
        }
        return s;
    }
};
