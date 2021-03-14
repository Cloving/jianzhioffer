class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (root) dfs(root, target);
        return res;
    }
    void dfs(TreeNode* node, int val) {
        temp.push_back(node->val);
        if (val - node->val == 0 && node->left == nullptr && node->right == nullptr) {
            res.push_back(temp);
        } else {
            if (node->left) dfs(node->left, val - node->val);
            if (node->right) dfs(node->right, val - node->val);
        }
        temp.pop_back();
    }
};