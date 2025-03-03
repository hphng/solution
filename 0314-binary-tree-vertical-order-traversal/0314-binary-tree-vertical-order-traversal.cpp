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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<pair<int, TreeNode*>> q;
        map<int, vector<int>> mp;
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }

        q.push({0, root});
        while(!q.empty()){
            auto [level, node] = q.front();
            q.pop();
            mp[level].push_back(node -> val);
            // int level = curr.first;
            // int val = curr.second;
            if(node -> left){
                q.push({level -1, node -> left});
            }
            if(node -> right){
                q.push({level + 1, node -> right});
            }
        }
        int i = 0;
        for(auto pair : mp){
            ans.push_back(pair.second);
            i++;
        }
        return ans;
    }
};