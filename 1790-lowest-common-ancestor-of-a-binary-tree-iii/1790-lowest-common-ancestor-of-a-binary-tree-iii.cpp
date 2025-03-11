/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> s;
        while(p){
            s.insert(p);
            p = p -> parent;
        }

        while(q){
            if(s.find(q) != s.end()){
                return q;
            }
            s.insert(q);
            q = q -> parent;
        }
        return q;
    }
};