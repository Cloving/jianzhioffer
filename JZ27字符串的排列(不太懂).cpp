/* 第一种: leetcode未考虑字典序 */

class Solution {
public:
    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }
private:
    vector<string> res;
    void dfs(string s, int x) {
        if(x == s.size() - 1) {
            res.push_back(s);                       // 添加排列方案
            return;
        }
        set<int> st;
        for(int i = x; i < s.size(); i++) {
            if(st.find(s[i]) != st.end()) continue; // 重复，因此剪枝
            st.insert(s[i]);
            swap(s[i], s[x]);                       // 交换，将 s[i] 固定在第 x 位
            dfs(s, x + 1);                          // 开启固定第 x + 1 位字符
            swap(s[i], s[x]);                       // 恢复交换
        }
    }
};

/* 第二种:  */
class Solution {
public:
    
    vector<string> Permutation(string str) {
        vector<string> res;
        PermutationStr(str, res, 0);
        sort(res.begin(), res.end());
        return res;
    }
    void PermutationStr(string str, vector<string>& result,int begin){
        if(begin == str.size() - 1){
            result.push_back(str);
        }else{
            for(int i = begin;i < str.size();++i){
                if(i!=begin && str[begin] == str[i]) continue;
                swap(str[begin],str[i]);
                PermutationStr(str,result,begin+1);
            }
        }
    }
};