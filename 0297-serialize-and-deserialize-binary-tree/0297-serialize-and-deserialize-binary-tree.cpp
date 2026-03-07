/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void preorder(TreeNode* root, string& ans) {
        if (!root) {
            ans += "null/";
            return;
        }
        ans += to_string(root->val) + "/";
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    TreeNode* build(vector<string>& nodes, int& i) {
        if(nodes[i] == "null"){
            i++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++;
        root -> left = build(nodes, i);
        root -> right = build(nodes, i);
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if (!root)
            return s;
        preorder(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return nullptr;
        }
        vector<string> nodes;
        string cur = "";
        for (int i = 0; i < data.length(); i++) {
            if (data[i] != '/') {
                cur += data[i];
            } else {
                nodes.push_back(cur);
                cur.clear();
            }
        }
        int i = 0;
        TreeNode* root = build(nodes, i);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));