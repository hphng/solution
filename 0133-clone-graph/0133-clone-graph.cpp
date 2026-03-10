/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*>  mp;

        Node* root = node;
        queue<Node*> q;

        Node* newRoot = new Node(root -> val);
        mp[root] = newRoot;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                Node* currentNode = q.front();
                q.pop();

                for(Node* child: currentNode -> neighbors){
                    if(mp.find(child) == mp.end()){
                        Node* newChild = new Node(child -> val);
                        mp[child] = newChild;
                        q.push(child);
                    }
                    mp[currentNode] -> neighbors.push_back(mp[child]);
                }
            }
        }

        return newRoot;

    }
};