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
        if(head == NULL || head -> next == NULL) return head;
        
        // calculate length 
        int len = 0;
        
        ListNode* curr = head;
        ListNode* tail = NULL;
        
        while(curr != NULL) {
            len++;
            // last node
            if(curr -> next == NULL) tail = curr;
            
            curr = curr -> next;
        }
        
        // if k is equal to len so there is not need to rotate list
        if(k == len) return head;
        
        // if k is multiple of len then just return head
        if(k > len && (k % len) == 0) return head;
        
        // if k is not the multiple of len
        // k will be updated and that's how many rotation we need to do
        if(k > len) k = (k % len);
        
        // here k will be smaller than len
        
        curr = head;
        
        for(int i = 1; i < len - k; i++) {
            curr = curr -> next;
        }
        
        // curr -> next element will be new head
        // first connect tail with current head
        tail -> next = head;
        // break curr -> next 
        ListNode* newHead = curr -> next;
        curr -> next = NULL;
        
        
        return newHead;
    }
};

// tc -> O(n)
// sc -> O(1)