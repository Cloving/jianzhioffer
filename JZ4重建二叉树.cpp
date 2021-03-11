/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* rebuild(vector<int>& pre, int preLeft, int preRight, vector<int>& vin, int vinLeft, int vinRight) {
        if (preLeft > preRight) {
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[preLeft]);
        for (int i = 0; i < vin.size(); ++i) {
            if (vin[i] == root -> val) {
                root -> left = rebuild(pre, preLeft + 1, preLeft + i - vinLeft, vin, vinLeft, i - 1);
                root -> right = rebuild(pre, preLeft + i - vinLeft + 1, preRight, vin, i + 1, vinRight);
            }
        }
        return root;
    }
    
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return rebuild(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
};