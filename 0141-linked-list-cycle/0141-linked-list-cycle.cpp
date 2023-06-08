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
    bool hasCycle(ListNode *head) {
        // use hasing 
        unordered_set<ListNode*> uset;
        
        ListNode* curr = head;
        
        while(curr != NULL) {
            // if node is present in the hashmap then cycle is there 
            if(uset.find(curr) != uset.end()) {
                return true;
            }
            
            uset.insert(curr);
            curr = curr -> next;
        }
        
        return false;
    }
};

// tc -> O(n)
// sc -> O(n)