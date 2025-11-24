/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct CompareListNode {
    bool operator()(ListNode* a, ListNode* b) const {
        return a -> val > b -> val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareListNode> pq;
        for(auto root: lists){
            if(root)
                pq.push(root);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(!pq.empty()){
            ListNode* smallest = pq.top();
            pq.pop();
            cur -> next = smallest;
            cur = cur -> next;
            if(smallest -> next){
                pq.push(smallest -> next);
            }
        }
        return dummy -> next;
    }
};