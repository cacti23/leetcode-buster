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
    
    
    while(l1 || l2) {
        let sum = carry;
        
        if(l1) {
            sum += l1.val;
        }
        
        if(l2) {
            sum += l2.val;
        }
        
        const digit = sum % 10;
        carry = Math.floor(sum / 10);
        
        if(l1) {
            l1.val = digit;
            current.next = l1;
        } else if(l2) {
            l2.val = digit;
            current.next = l2;
        } 
        
        current = current.next;
        l1 = l1?.next;
        l2 = l2?.next;
        
    }
        
    if(carry !== 0) {
        current.next = new ListNode(carry);
    }
        
    return dummyHead.next;
};