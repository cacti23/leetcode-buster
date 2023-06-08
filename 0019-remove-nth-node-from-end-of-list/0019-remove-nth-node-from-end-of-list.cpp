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
        
        ListNode* curr = head;
        int len = 0;
        
        // calculate length
        while(curr != NULL) {
            len++;
            curr = curr -> next;
        }
        
        curr = dummy;
        
        // now we have to traverse till totalNode - n which is the node just before the on we want to delete 
        for(int i = 0; i < len - n; i++) {
            curr = curr -> next;
        }
        
        // in case if len is equal to n then above for loop wont run and curr will be at dummy only
        ListNode* nodeToRemove = curr -> next;
        curr -> next = nodeToRemove -> next;
        delete nodeToRemove;
        
        
        return dummy -> next;
    }
};