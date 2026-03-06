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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = new ListNode(0, head);
        ListNode* dummy = res;

        ListNode* tmp = head;
        for(int i = 0; i < n; i++){
            tmp = tmp -> next;
        }

        ListNode* prev = res;
        while(tmp) {
            tmp = tmp -> next;
            prev = prev -> next;
        }

        prev -> next = prev -> next -> next;
        ListNode* ans = res -> next;
        delete res;
        return ans;
    }
};