/* 第一种: */
#include <unordered_map>
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int maxValue = INT_MIN;
        unordered_map<int, int> mp;
        for (auto i : numbers) {
            mp[i]++;
            maxValue = max(mp[i], maxValue);
        }
        for(auto iter = mp.begin(); iter != mp.end(); iter++){
            if(iter->second>numbers.size()/2)
                return iter->first;
        }
        return 0;
    }
};

/* 第二种: */
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());
        int temp = numbers[numbers.size()/2];
        int cnt = 0;
        for (auto i : numbers) {
            if (temp == i) {
                cnt++;
            }
        }
        if (cnt > numbers.size()/2) {
            return temp;
        } else {
            return 0;    
        }
    }
};

/* 第三种: */
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int cond;
        int cnt = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            if (cnt == 0) {
                cond = numbers[i];
                cnt++;
            } else {
                if (cond != numbers[i]) {
                    cnt--;
                } else {
                    cnt++;
                }
            }
        }
        cnt = 0;
        for (auto i : numbers) {
            if (i == cond) cnt++;  
        }
        if (cnt > numbers.size()/2) {
            return cond;
        }
        return 0;
    }
};



