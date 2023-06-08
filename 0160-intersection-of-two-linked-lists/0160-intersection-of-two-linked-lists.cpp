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
        // using hasing approach        
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        
        unordered_set<ListNode*> uset;
        // insert all elements of headA list into hashSet
        while(curr1 != NULL) {
            uset.insert(curr1);
            
            curr1 = curr1 -> next;
        }
        
        // traverse over headB list and check if element is present in set 
        while(curr2 != NULL) {
            // if the element is present in the hashSet
            if(uset.find(curr2) != uset.end()) {
                return curr2;
            }
            
            curr2 = curr2 -> next;
        }
        
        return NULL;
    }
};

// tc -> O(n + m)
// sc -> O(m) -> since we are inserting only headA element to the list