#include <unordered_map>
class Solution {
public:
    queue<char> que;
    unordered_map<char, int> umap;
    //Insert one char from stringstream
    void Insert(char ch) {
         if (umap.find(ch) == umap.end()) {
             que.push(ch);
         }
        umap[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        while (!que.empty()) {
            if (umap[que.front()] == 1) {
                return que.front();
            } else {
                que.pop();
            }
        }
        return '#';
    }
};