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
    unordered_set<int> need2;
    unordered_set<int> nums2;

    void dfs(TreeNode* root, bool isRoot1, int sum){
        if(!root){
            return;
        }
        if(isRoot1){
            need2.insert(sum - root -> val);
        } else {
            nums2.insert(root -> val);
        }
        dfs(root -> left, isRoot1, sum);
        dfs(root -> right, isRoot1, sum);
    }

    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        dfs(root1, true, target);
        dfs(root2, false, target);

        for(auto x: need2){
            if(nums2.contains(x)){
                return true;
            }
        }
        return false;
    }
};