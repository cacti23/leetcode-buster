/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // can use two for loops
        // canuse hashing map or set
        // using turtoise and hare approach
        if(head == NULL || head -> next == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // detect cycle
        do {
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(slow == fast) break;
        } while(fast != NULL && fast -> next != NULL);
        
        // if cycle is not present 
        if(slow != fast) return NULL;
        
        // if cycle is present 
        fast = head;
        
        while(fast != slow) {
            fast = fast -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
};

// tc -> O(N)
// sc -> O(1)