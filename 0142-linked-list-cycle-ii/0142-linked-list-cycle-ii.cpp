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
        // use hashing 
        if(head == NULL || head -> next == NULL) return NULL;
        
        // create hashset
        unordered_set<ListNode*> uset;
        
        ListNode* curr = head;
        
        // this while loop will not go infinite because if loop is there it will return and if not the curr will becomes null
        while(curr != NULL) {
            // if curr is present in the set then there is the loop and curr is the entry point 
            if(uset.find(curr) != uset.end()) {
                return curr;
            }
            
            uset.insert(curr);
            curr = curr -> next;
        }
        
        return NULL;
    }
};

// tc -> O(n)
// sc -> O(n)