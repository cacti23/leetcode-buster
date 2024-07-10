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
    let head = new ListNode(-1);
    let c1, c2, sum = 0, carry = 0, digit = 0;
    let temp = head;
    
    while(l1 !== null && l2 !== null) {
        c1 = l1;
        c2 = l2;
        
        l1 = l1.next;
        l2 = l2.next;
        
        sum = c1.val + c2.val + carry;
        carry = Math.floor(sum / 10);
        digit = sum % 10;
        
        // use c1 node's to store the new valu
        c1.val = digit
        temp.next = c1;
        temp = c1;
    }
    
    while(l1 !== null) {
        c1 = l1;
        sum = l1.val + carry;
        carry = Math.floor(sum / 10);
        digit = sum % 10;
        
        l1 = l1.next;
        
        c1.val = digit
        temp.next = c1;
        temp = c1;
    }
    
    while(l2 !== null) {
        c2 = l2;
        sum = l2.val + carry;
        carry = Math.floor(sum / 10);
        digit = sum % 10;
        
        l2 = l2.next;
        
        c2.val = digit
        temp.next = c2;
        temp = c2;
    }
    
    if(carry > 0) {
        temp.next = new ListNode(carry);    
    }
    
    return head.next;
};