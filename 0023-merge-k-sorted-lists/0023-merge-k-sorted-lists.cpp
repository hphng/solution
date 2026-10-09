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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>> >pq;

        ListNode* ans = new ListNode(0);
        for(ListNode* list: lists) {
            if(list)
                pq.push({list -> val, list});
        }

        ListNode* cur = ans;
        while(!pq.empty()) {
            auto [_, curNode] = pq.top();
            pq.pop();

            cur -> next = curNode;
            cur = cur -> next;

            if(curNode -> next) {
                pq.push({curNode->next -> val, curNode -> next});
            }
        }

        return ans -> next;

    }
};