/* 第一种: 非递归 */
class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if (!pRoot) return 0;
        int res = 0;
        queue<TreeNode* > que;
        que.push(pRoot);
        while(!que.empty()) {
            int len = que.size();
            while (len--) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res++;
        }
        return res;
    }
};


/* 第二种: 递归 */
class Solution {
public:
    int TreeDepth(TreeNode* pRoot){
        if(!pRoot) return 0 ;
            return max(1+TreeDepth(pRoot->left), 1+TreeDepth(pRoot->right));
    }
};