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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        
        // extra linked list apraoch 
        ListNode* ansHead = NULL;
        ListNode* curr = NULL;
        
        while(head1 != NULL && head2 != NULL) {
            // value at head 1 is less than value at head2
            if(head1 -> val < head2 -> val) {
                // this condition anywhere in this code signifies that 
                // this is the first element in the ans list 
                if(ansHead == NULL) {
                    // intialize the ansHead and curr;
                    ansHead = new ListNode(head1 -> val);
                    curr = ansHead;
                } else {
                    curr -> next = new ListNode(head1 -> val);
                    curr = curr -> next;
                }
                
                head1 = head1 -> next;
            }
            // vice versa  
            else {
                if(ansHead == NULL) {
                    // intialize the ansHead and curr;
                    ansHead = new ListNode(head2 -> val);
                    curr = ansHead;
                } else {
                    curr -> next = new ListNode(head2 -> val);
                    curr = curr -> next;
                }
                
                head2 = head2 -> next;
            }
        }
        
        // if len1 different than len2
        
        // process remaining elements of linked list
        
        while(head1 != NULL) {
            if(ansHead == NULL) {
                ansHead = new ListNode(head1 -> val);
                curr = ansHead;
            } else {
                curr -> next = new ListNode(head1 -> val);
                curr = curr -> next;
            }
 
            head1 = head1 -> next;
        }
        
        while(head2 != NULL) {
            if(ansHead == NULL) {
                ansHead = new ListNode(head2 -> val);
                curr = ansHead;
            } else {
                curr -> next = new ListNode(head2 -> val);
                curr = curr -> next;
            }
            
            head2 = head2 -> next;
        }
        
        return ansHead;
    }
};

// tc -> O(n + m)
// sc -> O(n + m)