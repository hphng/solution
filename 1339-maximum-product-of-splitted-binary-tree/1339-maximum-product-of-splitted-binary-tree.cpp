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
    void findSum(TreeNode* root, int& sum){
        if(!root) 
            return;
        sum += root -> val;
        findSum(root -> left, sum);
        findSum(root -> right, sum);
    }

    int dfs(TreeNode* root, long long& maxi, const int& sum){
        if(!root){
            return 0;
        }

        // if(!root -> left && !root -> right){
        //     return root -> val;
        // }

        int left = dfs(root -> left, maxi, sum);
        int right = dfs(root -> right, maxi, sum);
        int cur = left + right + root -> val;

        maxi = max(maxi, static_cast<long long> (cur) * (sum - static_cast<long long> (cur)));
        return cur; 
    }

    int maxProduct(TreeNode* root) {
        const int MOD = 1e9 + 7;

        int sum = 0;
        findSum(root, sum);

        long long maxi = 0;
        dfs(root, maxi, sum);

        maxi = maxi % MOD;
        return static_cast<int> (maxi);

    }
};