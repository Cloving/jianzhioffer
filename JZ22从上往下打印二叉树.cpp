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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;  
        if (root == NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            res.push_back(temp->val);
            
            if (temp->left) que.push(temp->left);
            if (temp->right) que.push(temp->right);
        }
        return res;
    }
};