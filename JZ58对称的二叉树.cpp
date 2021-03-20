/* 第一种: 递归 */
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        return isSame(pRoot, pRoot);
    }
    bool isSame(TreeNode* node1, TreeNode* node2) {
        if (!node1 && !node2) return true;
        if (!node1 || !node2) return false;
        return node1->val == node2->val && isSame(node1->left, node2->right) && isSame(node1->right, node2->left);
    }
};

/* 第二种: 非递归(队列),使用栈是同样的效果 */
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if (!pRoot) return true;
        queue<TreeNode*> que;
        que.push(pRoot->left);
        que.push(pRoot->right);
        while (!que.empty()) {
            TreeNode* leftNode = que.front(); que.pop();    
            TreeNode* rightNode = que.front(); que.pop();
            if (!leftNode && !rightNode) {
                continue;
            }
            if (!leftNode || !rightNode || leftNode->val != rightNode->val) {
                return false;
            }
            que.push(leftNode->left);
            que.push(rightNode->right);   
            que.push(leftNode->right);
            que.push(rightNode->left);
        }
        return true;
    }
};