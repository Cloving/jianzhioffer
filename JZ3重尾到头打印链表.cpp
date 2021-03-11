/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

/* 第一种 */
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        while (head != NULL) {
            res.push_back(head -> val);
            head = head -> next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/* 第二种 */
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if (head == NULL) {
            return res;
        }
        res = printListFromTailToHead(head -> next);
        res.push_back(head -> val);
        return res;
    }
};

/* 第三种 */
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* temp;
        while (cur) {
            temp = cur -> next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        vector<int> res;
        while (pre) {
            res.push_back(pre -> val);
            pre = pre -> next;
        }
        return res;
    }
};