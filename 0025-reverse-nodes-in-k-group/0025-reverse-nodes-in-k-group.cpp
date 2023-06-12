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
    ListNode* solve(ListNode* head, int k, int &len) {
        // base case 
        if(len < k || head == NULL) {
            return head;
        }
        
        // reverse logic
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        int temp = k;
        while(temp > 0) {
            ListNode* tempNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = tempNode;
            
            temp--;
        }
        
        int updatedLen = len - k;
        
        ListNode* remHead = solve(curr, k, updatedLen);
        
        head -> next = remHead;
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        // using recursive appraoch 
        if(head == NULL || head -> next == NULL) return head;
        
        // calculate length of the linked list
        ListNode* curr = head;
        int len = 0;
        
        while(curr != NULL) {
            len++;
            curr = curr -> next;
        }
        
        ListNode* newHead = solve(head, k, len);
        
        return newHead;
    }
};