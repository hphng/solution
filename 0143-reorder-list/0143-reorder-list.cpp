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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        //reverse the after half
        ListNode* cur = slow -> next;
        ListNode* prev = nullptr;
        while(cur) {
            ListNode* tmp = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = tmp;
        }
        slow -> next = nullptr;
        ListNode* ans = new ListNode();
        cur = ans;
        ListNode* first = head;
        ListNode* second = prev;
        
        while(first && second){
            ListNode* tmp1 = first -> next;
            ListNode* tmp2 = second -> next;
            first -> next = second;
            second -> next = tmp1;
            first = tmp1;
            second = tmp2;
        }


    }
};