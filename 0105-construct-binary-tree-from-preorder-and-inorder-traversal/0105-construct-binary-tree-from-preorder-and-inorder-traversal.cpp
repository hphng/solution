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
    int pre;
    unordered_map<int, int> mp;

    TreeNode* build(vector<int>& preorder, int start, int end) {
        if(start > end) return nullptr;

        int rootVal = preorder[pre];
        pre++;
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];

        TreeNode* left = build(preorder, start, mid -1);
        TreeNode* right = build(preorder, mid +1, end);

        root -> left = left;
        root -> right = right;
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mp.clear();
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        pre = 0;
        return build(preorder, 0, inorder.size()-1);
    }
};