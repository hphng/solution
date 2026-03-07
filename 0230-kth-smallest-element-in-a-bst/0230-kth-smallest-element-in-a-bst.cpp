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
    int ans = -1;
    int count = 0;
    void dfs(TreeNode* root, int& k) {
        if(!root) return;
        dfs(root -> left, k);
        count++;
        if(count == k) {
            ans = root -> val;
        }
        dfs(root -> right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        dfs(root, k);
        return ans;
    }
};