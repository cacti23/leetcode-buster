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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // using brute force 
        ListNode* ans = new ListNode(-1);
        
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        
        // outer loop selects all elements of headA list one by one
        while(curr1 != NULL) {
            // inner loop selects all elements of headB list one by one
            curr2 = headB;
            while(curr2 != NULL) {
                if(curr1 == curr2) {
                    ans = curr1;
                    return ans;
                }
                
                curr2 = curr2 -> next;
            }
            
            curr1 = curr1 -> next;
        }
        
        return NULL;
    }
};

// tc -> O(n * m)
// sc -> O(1)