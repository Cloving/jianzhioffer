class Solution {
public:
  string PrintMinNumber(vector<int> numbers) {
    string str;
    sort(numbers.begin(), numbers.end(), cmp);
    for (auto i : numbers) {
        str += to_string(i);
    }
    return str;
  }
  static bool cmp(int a, int b) {
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);
    return s1 < s2;
  }
};