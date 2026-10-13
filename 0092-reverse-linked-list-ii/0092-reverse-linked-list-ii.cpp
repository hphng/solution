/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
https://leetcode.com/problems/reverse-linked-list-ii/$0 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return nullptr;

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;

        int count = 0;
        ListNode* tmp = dummy;

        while(tmp && count + 1 < left) {
            tmp = tmp -> next;
            count++;
        }

        ListNode* leftNode = tmp;
        tmp = head;
        count = 1;

        while(tmp && count <= right) {
            tmp = tmp -> next;
            count++;
        }        

        ListNode* rightNode = tmp;

        ListNode* cur = rightNode;
        tmp = leftNode -> next;
        while(tmp != rightNode) {
            ListNode* nextNode = tmp -> next;
            tmp -> next = cur;
            cur = tmp;

            tmp = nextNode;
        }

        //cur with the node end, dummy -> next is node start
        leftNode -> next = cur;
        ListNode* newHead = dummy -> next;
        delete dummy;
        return newHead;
    }
};