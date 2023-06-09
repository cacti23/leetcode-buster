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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr != NULL) {
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL) return true;
        // using slow and fast pointers 
        
        // first find the middle of linked list 
        ListNode* slow = head;
        ListNode* fast = head;
        
        // now the while loop condition will be written in a way that 
        // for even length linked list like 4 middle element index will be 1
        // for odd length linked list like 4 middle element index will be 2
        while(fast -> next != NULL && fast -> next -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        // now slow has the middle element as it would map to a 0 based index
        // then reverse the linked list from slow -> next
        ListNode* nodeToConnect = reverse(slow -> next);
        // previously it was 1 -> 2 -> 3 -> 2 -> 1
        // slow pointer is at 3 and we need to reverse 2 -> 1 which reverse function did 
        // now need to update slow -> next to point to one
        slow -> next = nodeToConnect;
        
        // now move slow to its next element 
        slow = slow -> next;
        
        // so for this 1 -> 2 -> 3 -> 1 -> 2 updated linked list 
        // set slow at 1 (2nd one) and dummy at 1 (1st one)
        ListNode* dummy = head;
        
        // now use loop to check 
        while(dummy != NULL && slow != NULL) {
            if(dummy -> val != slow -> val) return false;
            
            dummy = dummy -> next;
            slow = slow -> next;
        }
        
        return true;
    }
};

// tc -> O(n/2)+O(n/2)+O(n/2)
// sc -> O(1)













