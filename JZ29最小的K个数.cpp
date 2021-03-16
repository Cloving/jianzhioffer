/* 第一种: */
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k > input.size()) return res;
        sort(input.begin(), input.end());
        for (int i = 0; i < k; ++i) {
            res.push_back(input[i]);
        }
        return res;
    }
};

/* 第二种: 堆排序 */
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.size() < k) {
        	return res;
    	  }
        for(int len = k/2-1; len >= 0; len--) {
            adjustMaxHeap(input, len, k-1);
        }
        for(int i = k;i < input.size(); i++) {
            if(input[i] < input[0]) {
                swap(input[0], input[i]);
                adjustMaxHeap(input, 0, k-1);
            }
        }
        for(int i = 0; i < k; i++) {
            res.push_back(input[i]);
        }
        return res;
    }
    void adjustMaxHeap(vector<int>& vec, int pos, int length) {
        int temp, child;
        for(temp = vec[pos]; 2*pos + 1 <= length; pos = child) {
            child = 2*pos + 1;
            if(child < length&&vec[child] < vec[child+1]) {
                child++;
            }
            if(vec[child] > temp) {
                vec[pos] = vec[child];
            } else {
                break;
            }
        }
        vec[pos] = temp;
	}
};

/* 第三种: 优先队列 */
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size()) return res;
        priority_queue<int, vector<int>> pq;
        for (int i = 0; i < input.size(); ++i) {
            if (pq.size() < k) {
                pq.push(input[i]);
            } else {
                if (input[i] < pq.top()) {
                    pq.pop();
                    pq.push(input[i]);
                }
            }
        }
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
