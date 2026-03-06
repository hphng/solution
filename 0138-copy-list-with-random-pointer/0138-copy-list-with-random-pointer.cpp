/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp; //mp[old] = new

        Node* tmp = head;
        Node* ans = new Node(0);
        Node* cur = ans;
        while(tmp) {
            Node* newNode = new Node(tmp -> val);
            cur -> next = newNode;
            mp[tmp] = newNode;
            tmp = tmp -> next;
            cur = cur -> next;
        }
        //random
        tmp = head;
        cur = ans -> next;
        while(tmp) {
            cur -> random = mp[tmp -> random];
            cur = cur -> next;
            tmp = tmp -> next;
        }
        Node* dummy = ans;
        ans = ans -> next;
        delete dummy;
        return ans;
    }
};