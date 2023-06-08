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
        // if ll has only single element 
        if(head -> next == NULL) return NULL;
        
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // move fast n times 
        // so totalNode - n nodes remains after fast 
        // move both slow and fast by one and when fast is at the end 
        // slow will be at totalNode - n
        
        // this loop will run n times
         while(n > 0) {
                fast = fast -> next;
                n--;
        }
        // now fast is at n position
        
                
        while(fast -> next != NULL) {      
            slow = slow -> next;
            fast = fast -> next;
        }
        
        // now slow is at total - n node from begining 
        ListNode* nodeToRemove = slow -> next;
        slow -> next = nodeToRemove -> next;
        
        delete nodeToRemove;
        
        
        return dummy -> next;
    }
};

// m is the mth node from end 
// tc -> O(m) + O(totalNode - m) -> O(n)
// sc -> O(1)