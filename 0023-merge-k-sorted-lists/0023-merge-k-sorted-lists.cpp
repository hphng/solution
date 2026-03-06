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
class Solution {
public:
    struct Compare {
        bool operator()(ListNode *p, ListNode *q )
        {
            return p->val > q->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <ListNode*, vector<ListNode*>, Compare> pq;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        for(auto& node: lists) {
            if(node) {
                pq.push(node);
            }
        } 

        while(!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            cur -> next = top;
            cur = cur -> next;
            if(top -> next) {
                pq.push(top -> next);
            }
        }

        ListNode* ans = dummy -> next;
        delete dummy;
        return ans;
    }
};