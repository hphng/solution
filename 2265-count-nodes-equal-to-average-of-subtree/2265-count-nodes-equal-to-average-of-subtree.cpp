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
    pair<int, int> dfs(TreeNode* root){
        if(!root){
            return {0, 0};
        }

        if(!root -> left && !root -> right){
            cout << root -> val << endl;
            ans++;
            return {root -> val, 1};
        }

        auto [sumLeft, numLeft] = dfs(root -> left);
        auto [sumRight, numRight] = dfs(root -> right);

        int sum = sumLeft + sumRight + root -> val;
        int numberOfNode = numLeft + numRight + 1;

        int average = floor(sum/numberOfNode);
        if(average == root -> val) {
            ans++;
            cout << root -> val << endl;
        } 

        return {sum, numberOfNode};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};