class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        ListNode *Head = new ListNode(-1);
        Head->next = pHead;
        ListNode *pre = Head;
        ListNode *cur = Head->next;
        while (cur != NULL) {
            if (cur->next != NULL && cur->val == cur->next->val) {
                cur = cur->next;
                while (cur->next != NULL && cur->val == cur->next->val) {
                    cur = cur->next;
                }
                cur = cur->next;
                pre->next = cur;  /* 临时存放 */  
            } else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        return Head->next;  /* 避免开头即重复,不返回pHead */
    }
};