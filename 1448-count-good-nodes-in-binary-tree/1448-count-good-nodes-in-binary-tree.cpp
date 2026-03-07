/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int maxi) {
        if(!root) return 0;
        maxi = max(maxi, root -> val);
        int left = dfs(root -> left, maxi);
        int right = dfs(root -> right, maxi);

        if(root -> val >= maxi){
            return left + right + 1;
        }
        return left + right;
    }
    int goodNodes(TreeNode* root) {
        int ans = dfs(root, root -> val);
        return ans;
    }
};