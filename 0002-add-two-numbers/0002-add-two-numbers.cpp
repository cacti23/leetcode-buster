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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* ansHead = new ListNode(-1);
        ListNode* ansCurr = ansHead;
        
        int carry = 0;
        
        while(curr1 != NULL && curr2 != NULL) {
            int sum = curr1 -> val + curr2 -> val + carry;
            
            // sum can range from 0 -> 18
            // check if carry is there or not 
            carry = sum / 10;
            
            sum = sum % 10;
            
            ansCurr -> next = new ListNode(sum);
            
            ansCurr = ansCurr -> next;
            
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        }
        
        // after the above loop either elements of l1 remains or elements of l2 remains
        while(curr1 != NULL) {
            int sum = curr1 -> val + carry;
            
            carry = sum / 10;
            
            sum  = sum % 10;
            
            ansCurr -> next = new ListNode(sum);
            ansCurr = ansCurr -> next;
            
            curr1 = curr1 -> next;
        }
        
        while(curr2 != NULL) {
            int sum = curr2 -> val + carry;
            
            carry = sum / 10;
            
            sum  = sum % 10;
            
            ansCurr -> next = new ListNode(sum);
            ansCurr = ansCurr -> next;
            
            curr2 = curr2 -> next;
        }
        
        // maybe carry is still there 
        if(carry > 0) {
            ansCurr -> next = new ListNode(carry);
        }
        
        return ansHead -> next;
        
        
    }
};

// tc -> O(n + m)
// sc -> O(n + m)