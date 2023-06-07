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
        // without using extra space 
        // head1 and head2 value will keep changing they will act as curr 1 and curr 2
        
        ListNode* ansHead = NULL;
        ListNode* ansCurr = NULL;
        
        while(head1 != NULL && head2 != NULL) {
            // head1 val is less than head2 val
            if(head1 -> val < head2 -> val) {
                // check for first element
                if(ansHead == NULL) {
                    ansHead = head1;
                    ansCurr = ansHead;
                } else {
                    ansCurr -> next = head1;
                    ansCurr = ansCurr -> next;
                }
                
                head1 = head1 -> next;
            }
            // vice versa
            else {
                if(ansHead == NULL) {
                    ansHead = head2;
                    ansCurr = ansHead;
                } else {
                    ansCurr -> next = head2;
                    ansCurr = ansCurr -> next;                    
                }
                
                head2 = head2 -> next;
            }
        }
        
        // process remaining elements in head1 and head2

        while(head1 != NULL) {
            if(ansHead == NULL) {
                ansHead = head1;
                ansCurr = ansHead;
            } else {
                ansCurr -> next = head1;
                ansCurr = ansCurr -> next;
            }

            head1 = head1 -> next;
        }
        
        while(head2 != NULL) {
            if(ansHead == NULL) {
                ansHead = head2;
                ansCurr = ansHead;
            } else {
                ansCurr -> next = head2;
                ansCurr = ansCurr -> next;
            }

            head2 = head2 -> next;
        }
        
        return ansHead;
    }
};