/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* node = root;
        while(node){
            Node* temp = new Node(0);
            Node* cur = temp;

            while(node){
                if(node -> left){
                    cur -> next = node -> left;
                    cur = cur -> next;
                }

                if(node -> right){
                    cur -> next = node -> right;
                    cur = cur -> next;
                }
                node = node -> next;
            }
            node = temp -> next;
        }
        return root;
    }
};