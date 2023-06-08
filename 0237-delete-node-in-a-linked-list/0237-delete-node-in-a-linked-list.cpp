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
    void deleteNode(ListNode* node) {
        // given node is not the last element of the linked list 
        // means at minimum there will be another node after given node 
        ListNode* nextNode = node -> next;
        
        // copy value of next node to given node 
        node -> val = nextNode -> val;
        
        node -> next = nextNode -> next;
        
        delete nextNode;
        
        return;
    }
};