/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/

/* 第一种: 找到父节点转换成中序遍历再找*/
class Solution {
public:
    vector<TreeLinkNode*> temp;
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        TreeLinkNode* cur = pNode;
        while (cur -> next) {
            cur = cur->next;
        }
        Inorder(cur);
        for (int i = 0; i < temp.size() - 1; ++i) {
            if (temp[i] == pNode) {
                return temp[i+1];
            }
        }
        return NULL;
    }
    void Inorder( TreeLinkNode* cur) {
        if (!cur) return;
        Inorder(cur->left);
        temp.push_back(cur);
        Inorder(cur->right);
    }
};

/* 第二种: 直接找*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode->right) {
            pNode = pNode->right;
            while (pNode->left) {
                pNode = pNode->left;
            }
            return pNode;
        }
        while (pNode->next && pNode->next->left == pNode) {
            return pNode->next;
        }
        while (pNode->next && pNode->next->right == pNode) {
            pNode = pNode->next;
        }
        return pNode->next;
    }
};

