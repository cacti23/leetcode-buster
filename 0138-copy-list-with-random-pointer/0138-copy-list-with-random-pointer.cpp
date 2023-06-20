/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        
        // modify the current linked list
        // insert new element with same value next to the old element with that value
        Node* curr = head;
        
        while(curr != NULL) {
            // insert new element 
            Node* tempNew = new Node(curr -> val);
            Node* tempNext = curr -> next;
            
            curr -> next = tempNew;
            tempNew -> next = tempNext;
            
            // skip the new element and move to next old one
            curr = tempNew -> next;
        }
        
        // now the list will contain for example 1, 1, 7, 7, 13, 13 ....
        
        // now copy the random pointers 
        curr = head;
        while(curr != NULL && curr -> next != NULL) {
            // copy random pointer of old element to random pointer of new element 
            Node* tempRand = curr -> random;
            
            // next of this random pinter will be the one to copy in new pointer
            Node* tempNew = curr -> next;
            if(tempRand != NULL) {
                tempNew -> random = tempRand -> next;
            } else {
                tempNew -> random = NULL;
            }
            
            // skip the new element and move to old one
            curr = tempNew -> next;
        }
        
        // we have copied random pointer successfully
        // now create a answer linked list 
        Node* dummyHead = new Node(-1);
        Node* tempCurr = dummyHead;
        
        curr = head;
        
        while(curr != NULL && curr -> next != NULL) {
            Node* tempNew = curr -> next;
            
            // remove new element form this list 
            curr -> next = tempNew -> next;
            
            tempCurr -> next = tempNew;
            
            tempCurr = tempCurr -> next;
            curr = curr -> next;
            
        }
        
        return dummyHead -> next;
    }
};

// tc -> O(n) + O(n) + O(n)
// sc -> O(1)