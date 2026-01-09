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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode* > q;
        unordered_map<TreeNode*, TreeNode* > mp; //child: parent
        unordered_set<TreeNode*> last;
        
        q.push(root);
        last.insert(root);
        mp[root] = root;

        while(!q.empty()){
            int size = q.size();
            unordered_set<TreeNode* > s;
            for(int i = 0; i < size; i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur -> left) {
                    q.push(cur -> left);
                    s.insert(cur -> left);
                    mp[cur-> left] = cur;
                }

                if(cur -> right) {
                    q.push(cur -> right);
                    s.insert(cur -> right);
                    mp[cur -> right] = cur;
                }
            }
            if(!s.empty())
                last = s;
        }

        unordered_set<TreeNode*> parent = last;

        while(parent.size() > 1){
            unordered_set<TreeNode*> upper;

            for(auto node: parent){
                TreeNode* p = mp[node];
                upper.insert(p);
            }

            parent = upper;
        }

        TreeNode* ans = *parent.begin();
        return ans;
    }
};