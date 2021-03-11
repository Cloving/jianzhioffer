/* 第一种: 非递归*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* res = new ListNode(-1);
        ListNode* cur = res;
        while (pHead1 && pHead2) {
            if (pHead1->val <= pHead2->val) {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            } else if (pHead1->val > pHead2->val){
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }
        if (pHead1) {
            cur -> next = pHead1;
        }
        if (pHead2) {
            cur -> next = pHead2;
        }
        return res->next;
    }
};

/* 第二种: 递归*/
class Solution {
public:
  ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    if (!pHead1) return pHead2;
    if (!pHead2) return pHead1;
    if (pHead1->val >= pHead2->val) {
      pHead2->next = Merge(pHead1, pHead2->next);
      return pHead2;
    } else {
      pHead1->next = Merge(pHead1->next, pHead2);
      return pHead1;
    }
  }
};

