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
    int findPosition(vector<int>& inorder, int n, int x)
    {
        for(int i = 0; i < n; i++)
            if(x == inorder[i])
                return i;
        return -1;
    }
    
    TreeNode* solution(vector<int>& preorder, vector<int> & inorder, int &index, int n, int start, int end )
    {
        if(index >= n || start > end)
            return NULL;
        int x = preorder[index++];
        TreeNode* root = new TreeNode(x);
        int position = findPosition(inorder, n, x);
        
        root -> left = solution(preorder, inorder, index, n, start, position-1);
        root -> right = solution(preorder, inorder, index, n, position +1, end);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        int n = preorder.size();
        TreeNode * ans = solution(preorder, inorder, preIndex, n, 0, n-1);
        
        return ans;
    }
};