class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode dummyHead;
        ListNode* ansCurr = &dummyHead;
        
        while(head1 != NULL && head2 != NULL) {
            if(head1->val < head2->val) {
                ansCurr->next = head1;
                head1 = head1->next;
            } else {
                ansCurr->next = head2;
                head2 = head2->next;
            }
            ansCurr = ansCurr->next;
        }
        
        // Attach the remaining elements of head1 or head2
        ansCurr->next = head1 ? head1 : head2;
        
        return dummyHead.next;
    }
};
