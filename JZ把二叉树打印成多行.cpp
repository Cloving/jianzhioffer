class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (!pRoot) return res;
        vector<int> temp;
        queue<TreeNode*> que;
        que.push(pRoot);
        while (!que.empty()) {
            int len = que.size();
            while (len--) {
                TreeNode* node = que.front();
                temp.push_back(node->val);
                que.pop();
                if (node -> left) que.push(node->left);
                if (node -> right) que.push(node->right);
            }
            res.push_back(temp);
            temp.clear();  
        }
        return res;
    }
};