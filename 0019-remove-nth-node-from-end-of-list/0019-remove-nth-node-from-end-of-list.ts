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

function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
    // find size
    let size = 0;
    let curr = head;
    
    while(curr != null) {
        size++;
        curr = curr.next;
    }
    
    if(size === 1) return null;
    
    // intead of getting the n node from last we can update n from front
    n = size - n + 1;
    
    // if first element needs to be removed
    if(n === 1) return head.next;
    
    curr = head;
    let prev = null;
    let count = 0;
    
    while(curr != null) {
        count++;
        if(count === n) {
            prev.next = curr.next;
        } else {
            prev = curr;
        }
        
        curr = curr.next;
    }
    
    return head;
};

// tc -> O(n)
// sc -> O(1)