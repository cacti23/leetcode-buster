/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function deleteMiddle(head: ListNode | null): ListNode | null {
    // fixing fast and slow at head not at dummy node is due to question requirement
    if(head === null || head.next === null) {
        return null;
    }
    
    let fast = head;
    let slow = head;
    let prev = null
    
    while(fast !== null && fast.next !== null) {
        fast = fast.next.next;
        prev = slow;
        slow = slow.next;
    }
    
    prev.next = slow.next;
    return head;
};

// tc -> O(n)
// sc -> O(1)