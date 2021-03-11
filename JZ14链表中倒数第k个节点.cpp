/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

/* 第一种: */
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        int len = 0;
        ListNode* cur = pHead;
        while (pHead) {
            len++;
            pHead = pHead -> next;
        }
        if (k > len) {
            return NULL;
        }
        int n = len - k;
        while(n--) {
            cur = cur -> next;    
        }
        return cur;
    }
};

/* 第二种: 快慢指针*/
class Solution {
public:
  ListNode* FindKthToTail(ListNode* pHead, int k) {
    ListNode* slow = pHead;
    ListNode* fast = pHead;
    while (k--) {
      if (fast) {
        fast = fast->next;
      } else {
        return NULL;
      }
    }
    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }
};