class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 || !pRoot2) return false;
        return isSubTree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
    
    bool isSubTree(TreeNode* p1, TreeNode* p2) {
        if (!p2) return true;
        if (!p1) return false;
        if (p1->val == p2->val) {
            return isSubTree(p1->left, p2->left) && isSubTree(p1->right, p2->right);
        } else {
            return false;
        }
    }
};