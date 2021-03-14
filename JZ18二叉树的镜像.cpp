class Solution {
public:
    TreeNode* Mirror(TreeNode* pRoot) {
        if (pRoot == NULL || (pRoot -> left == NULL && pRoot -> right == NULL)) {
            return pRoot;
        }
        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return pRoot;
    }
};

