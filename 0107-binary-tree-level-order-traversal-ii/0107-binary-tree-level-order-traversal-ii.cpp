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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<vector<int>> st;
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            for(int i = 0; i < n; i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur -> left){
                    q.push(cur -> left);
                }
                if(cur -> right){
                    q.push(cur -> right);
                }
                level.push_back(cur -> val);
            }
            st.push(level);
        }
        while(!st.empty()){
            vector<int> cur = st.top();
            st.pop();
            ans.push_back(cur);
        }
        return ans;
    }
};