/* 第一种: 递归 */
class Solution {
public:
    TreeNode* res;
    int m;
    void dfs(TreeNode* cur) {
        if (!cur || m < 1) return;
        dfs(cur->left);
        if (m == 1) res = cur;
        if (--m > 0) dfs(cur->right);
    }
    
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        res = NULL, m = k;
        dfs(pRoot);
        return res;
    }  
};

/* 第二种: 非递归 */
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (!pRoot) return nullptr; 
        TreeNode* p = pRoot;
        stack<TreeNode* > st;
        while (!st.empty() || p) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            TreeNode* cur = st.top();
            st.pop();
            if ((--k) == 0) return cur;
            p = cur->right;
        }
        return nullptr;
    }
};

