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
    // Helper function to reverse k nodes in the linked list and return the new head
    ListNode* reverseKNodes(ListNode* head, int k, int &remainingLen) {
        // Base case: return head if remaining length is less than k or head is NULL
        if(remainingLen < k || head == NULL) {
            return head;
        }
        
        // Initialize pointers for reverse logic
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        // Reverse k nodes in the linked list
        for (int i = 0; i < k; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        // Update remaining length
        remainingLen -= k;
        
        // Recursively reverse the remaining nodes in groups of k
        ListNode* remainingHead = reverseKNodes(curr, k, remainingLen);
        
        // Connect the reversed part to the remaining part
        head->next = remainingHead;
        
        // Return the new head of the reversed part
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Calculate the length of the linked list
        ListNode* curr = head;
        int len = 0;
        
        while(curr != NULL) {
            len++;
            curr = curr->next;
        }
        
        // Reverse nodes in k groups using the helper function
        ListNode* newHead = reverseKNodes(head, k, len);
        
        return newHead;
    }
};

