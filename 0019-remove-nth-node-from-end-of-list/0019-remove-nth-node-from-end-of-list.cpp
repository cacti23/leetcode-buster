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
        if(head -> next == NULL) return NULL;
        
        ListNode* curr = head;
        
        // calculate length 
        int len = 0;
        
        while(curr != NULL) {
            len++;
            curr = curr -> next;
        }
        
        // if n is equal to len then 
        // here ll with minimum size of 2 should only come
        if(len == n) return head -> next;
        
        // traverse linked list again to get the element to remove 
        ListNode* prev = new ListNode(-1);
        curr = head;
        
        for(int i = 0; i < len - n; i++) {
            prev = curr;
            curr = curr -> next;
        }
        
        // current has the element that needs to be removed
        prev -> next = curr -> next;
        curr -> next = NULL;
        
        delete curr;
        
        return head;
    }
};

// tc -> O(n) 
// sc -> O(1)
