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
    int ans = 0;
    void dfs(TreeNode* root, int target, int length){
        if(!root){
            return;
        }

        if(root -> val != target){
            length = 1;
        } else {
            length++;
        }

        ans = max(ans, length);
        dfs(root-> left, root -> val + 1, length);
        dfs(root -> right, root -> val + 1, length);
    }
    int longestConsecutive(TreeNode* root) {
        dfs(root, root -> val, 0);
        return ans;
    }
};