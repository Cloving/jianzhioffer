/* 第一种: */
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        unordered_set<ListNode*> st;
        while (pHead) {
            if (!st.count(pHead)) {
                st.insert(pHead);
                pHead = pHead->next;
            } else {
                return pHead;
            }
        }
        return NULL;
    }
};

/* 第二种: */
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode *slow = pHead, *fast = pHead;
        while (slow && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        if (!fast || !fast->next) {
            return NULL;
        }
        fast = pHead;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;     
        }
        return slow;
    }
};
