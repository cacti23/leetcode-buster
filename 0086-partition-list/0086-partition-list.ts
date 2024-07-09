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

function partition(head: ListNode | null, x: number): ListNode | null {
    let h1 = new ListNode(-1);
    let p1 = h1;
    let h2 = new ListNode(-1);
    let p2 = h2;
    
    let curr = head;
    
    while(curr !== null) {
        // if element is less than x then we add it to p1 else p2
        if(curr.val < x) {
            p1.next = curr;
            curr = curr.next;
            p1 = p1.next;
            p1.next = null;
        } else {
            p2.next = curr;
            curr = curr.next;
            p2 = p2.next;
            p2.next = null;
        }
    }
    
    // for case [1,4,3,2,5,2] -> 3;
    // h1 -1 -> 1 -> 2 -> 2 -> null; h2  -1 -> 4 -> 3 -> 5 -> null
    // move past the dummy node
    if(h1.next === null) {
        h2 = h2.next;
        
        return h2;
    }
    
    if(h2.next === null) {
        h1 = h1.next;
        
        return h1;
    }

    h1 = h1.next;
    h2 = h2.next;
    
    p1.next = h2;
    
    return h1;
};

// tc -> O(n)
// sc -> O(1)