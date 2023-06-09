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
        // use optimal approach two 
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        
        int switchCount = 0;
        
        // in this single loop we gonna travel both lists
        // if headA and headB has different len
        // if loop exists then curr1 will have answer 
        // if loop does not exists curr1 and curr2 will be NULL together after when they are from same distance at the end 
        while(curr1 != curr2) {
            // after first iteration curr1 and curr2 will be reset to the head of another linked list 
            curr1 = curr1 == NULL ? headB : curr1 -> next;
            curr2 = curr2 == NULL ? headA : curr2 -> next;
        }
        
        return curr1;
    }
};

// to understand this solution better
// first dry run with linked list with intersection 
// then linked list without intersection

// tc -> O(n + m)
// sc -> O(1)