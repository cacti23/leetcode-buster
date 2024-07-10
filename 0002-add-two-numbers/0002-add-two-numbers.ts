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

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    const dummyHead = new ListNode(-1);
    let current = dummyHead;
    let carry = 0;
    
    while(l1 !== null || l2 !== null || carry !== 0) {
        let sum = carry;
        
        if(l1 !== null) {
            sum += l1.val;
            l1 = l1.next;
        }
        
        if(l2 !== null) {
            sum += l2.val;
            l2 = l2.next;
        }
        
        const digit = sum % 10;
        carry = Math.floor(sum / 10);
        
        current.next = new ListNode(digit);
        current = current.next;
    }
    
    return dummyHead.next;
};