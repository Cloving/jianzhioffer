/* 第一种: */
#include <unordered_map>
class Solution {
public:
    unordered_map<TreeNode*, int> mp;
    int depth(TreeNode* node) {
        if (!node) return 0;
        if (mp.find(node) != mp.end()) return mp[node];
        return mp[node] = max(1+depth(node->left), 1+ depth(node->right));
    }
    
    bool judge(TreeNode* node) {
        if (!node) return true;
        return abs(mp[node->left] - mp[node->right]) <= 1 && judge(node->left) && judge(node->right);
    }
    
    bool IsBalanced_Solution(TreeNode* pRoot) {     
        depth(pRoot);
        return judge(pRoot);
    }
};

/* 第二种:  */
class Solution {
public:
    int depth(TreeNode *root) {
        if (!root) return 0;
        int ldep = depth(root->left);
        if (ldep == -1) return -1;
        int rdep = depth(root->right);
        if (rdep == -1) return -1;
        int sub = abs(ldep - rdep);
        if (sub > 1) return -1;
        return max(ldep, rdep) + 1;
    }
    bool IsBalanced_Solution(TreeNode* root) {
        return depth(root) != -1;
    }
};