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
    // head recursion
    void reverseListHelper(ListNode* curr, ListNode* prev, ListNode* &head) {
        if(curr == NULL) {
            // update head which we need to return 
            head = prev;
            return;
        }
        
        ListNode* next = curr->next;
        curr -> next = prev;
        
        reverseListHelper(next, curr, head);
    }
    
    ListNode* reverseList(ListNode* &head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        reverseListHelper(curr, prev, head);
        
        return head;
    }
};

// tc -> O(n)
// sc -> O(n) // for stack 
