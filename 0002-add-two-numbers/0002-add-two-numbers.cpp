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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* cur = ans;

        int carry = 0;
        while(l1 || l2) {
            int value1 = l1 ? l1 -> val: 0;
            int value2 = l2 ? l2 -> val: 0;

            int curValue = value1 + value2 + carry;
            if(curValue >= 10) {
                carry = 1;
                curValue -= 10;
            } else {
                carry  = 0;
            }

            ListNode* curNode = new ListNode(curValue);
            cur -> next = curNode;
            cur = cur -> next;
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
        }

        if(carry == 1){
            ListNode* curNode = new ListNode(1);
            cur -> next = curNode;
        }

        ListNode* dummy = ans;
        ans = ans -> next;
        delete dummy;
        return ans;
    }
};