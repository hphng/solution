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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tmp = dummy;
        while (list1 && list2) {
            ListNode* next1 = list1->next;
            ListNode* next2 = list2->next;

            if (list1->val < list2->val) {
                tmp->next = list1;
                list1->next = nullptr;
                list1 = next1;
            } else {
                tmp->next = list2;
                list2->next = nullptr;
                list2 = next2;
            }
            tmp = tmp -> next;
        }

        while (list1) {
            ListNode* next1 = list1->next;
            tmp->next = list1;
            list1->next = nullptr;
            list1 = next1;
            tmp = tmp -> next;
        }

        while (list2) {
            ListNode* next2 = list2->next;
            tmp->next = list2;
            list2->next = nullptr;
            list2 = next2;
            tmp = tmp -> next;
        }
        return dummy -> next;
    }
};