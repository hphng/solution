/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = nullptr;
    pair<bool, bool> dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || ans) {
            return {false, false};
        }

        auto [leftP, leftQ] = dfs(root -> left, p, q);
        auto [rightP, rightQ] = dfs(root -> right, p, q);

        bool hasP = leftP || rightP || root == p;
        bool hasQ = leftQ || rightQ || root == q;

        if(hasP && hasQ && !ans) {
            ans = root;
        }

        return {hasP, hasQ};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        dfs(root, p, q);
        return ans;
    }
};