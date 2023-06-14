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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;

        int len = 1;
        ListNode* tail = head;
        while(tail->next != NULL) {
            len++;
            tail = tail->next;
        }
        
        k %= len;
        if(k == 0) return head;

        ListNode* newTail = head;
        for(int i = 1; i < len - k; i++) {
            newTail = newTail->next;
        }

        tail->next = head;
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};