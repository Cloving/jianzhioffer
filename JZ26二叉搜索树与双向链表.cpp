/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* pre = NULL;
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (!pRootOfTree) {
            return NULL;
        }
        Convert(pRootOfTree->right);
        if (pre != NULL) {
            pRootOfTree->right = pre;
            pre->left = pRootOfTree;
        }
        pre = pRootOfTree;
        Convert(pRootOfTree->left);
        return pre;
    }
};