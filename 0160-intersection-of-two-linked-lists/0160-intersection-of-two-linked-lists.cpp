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
        // use length difference 
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        
        // find the len of headA ll 
        int len1 = 0;
        while(curr1 != NULL) {
            len1++;
            curr1 = curr1 -> next;
        }
        
        // find the len of headB ll 
        int len2 = 0;
        while(curr2 != NULL) {
            len2++;
            curr2 = curr2 -> next;
        }
        
        // find which one len is greater and move that curr to the difference
        int diff = 0;
        
        curr1 = headA;
        curr2 = headB;
        if(len1 > len2) {
            diff = len1 - len2;
            // move curr1 to diff times 
            while(diff > 0) {
                curr1 = curr1 -> next;
                diff--;
            }
        } else if(len2 > len1) {
            diff = len2 - len1;
            // move curr2 to diff times
            while(diff > 0) {
                curr2 = curr2 -> next;
                diff--;
            }
        }
        
        // after the above if and else if both curr1 and curr2 are at correct position 
        // not check if len1 and len2 are equal becuase curr1 and curr2 will be at the head only 
        
        while(curr1 != NULL && curr2 != NULL) {
            if(curr1 == curr2) {
                return curr1;
            }
            
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        }
        
        return NULL;
        
    }
};

// tc -> O(n + m)
// sc -> O(1)