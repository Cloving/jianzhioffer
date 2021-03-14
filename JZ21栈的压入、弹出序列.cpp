class Solution {
public:
  bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    if (pushV.empty() || popV.empty()) return false;
    vector<int> res;
    for (int i = 0, j = 0; i < pushV.size(); ++i) {
      res.push_back(pushV[i]);
      while (j < popV.size() && popV[j] == res.back()) {
        res.pop_back();
        j++;
      }
    }
    return res.empty();
  }
};