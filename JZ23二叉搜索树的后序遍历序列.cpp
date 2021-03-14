class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) return false;
        return judge(sequence, 0, sequence.size()-1);
    }
    
    bool judge(vector<int> seq, int left, int right) {
        if (left >= right) return true;
        int i = right;
        while (i > left && seq[i-1] > seq[right]) {
            i--;
        }
        for (int j = i-1; j >= left; j--) {
            if (seq[j] > seq[right]) {
                return false;
            }
        }
        return judge(seq, left, i-1) && judge(seq, i, right-1);
    }
};