// Definition of the ListNode structure
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base case: if the head is NULL or there is only one element in the list
        if(head == NULL || head -> next == NULL) return head;
        
        // Calculate the length of the linked list
        int len = 0;
        ListNode* cur = head;
        while(cur != NULL) {
            len++;
            cur = cur -> next;
        }
        
        // Create a dummy head node to simplify the process of reversing the list
        ListNode* dummyHead = new ListNode(-1);
        dummyHead -> next = head;
        
        // Initialize pointers pre, cur, and nex for traversing and reversing the list
        ListNode* pre = dummyHead;
        cur = pre -> next;
        ListNode* nex = cur -> next;
    
        // Iterate through the list while the remaining length is greater than or equal to k
        while(len >= k) {
            cur = pre -> next;
            nex = cur -> next;
            
            // Reverse the k-sized group of nodes
            int temp = k;
            while(temp > 1) {
                cur -> next = nex -> next;
                nex -> next = pre -> next;
                pre -> next = nex;
                nex = cur -> next;
                
                temp--;
            }
            
            // Move the pre pointer to the end of the current group
            pre = cur;
            // Update the remaining length of the list
            len -= k;
        }
        
        // Return the new head of the modified list
        return dummyHead -> next;
    }
};


// tc -> O((n / k) * k)
// sc -> O(1)