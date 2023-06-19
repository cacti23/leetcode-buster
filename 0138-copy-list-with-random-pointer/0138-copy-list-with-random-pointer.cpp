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
        
        // create a new linked list without copying random pointer
        Node* tempHead = new Node(-1);
        
        Node* curr = head;
        
        Node* tempCurr = tempHead;
        
        while(curr != NULL) {
            Node* newNode = new Node(curr -> val);
            tempCurr -> next = newNode;
            
            // move both pointers to next node
            tempCurr = tempCurr -> next;
            curr = curr -> next;
        }
        
        // new linked list is created without the random pointer
        curr = head;
        tempCurr = tempHead -> next;
        
        // create a hashmap that maps the old node with new nodes
        unordered_map<Node*, Node*> umap;
        
        while(curr != NULL) {
            umap[curr] = tempCurr;
            
            // move both pointers to next node
            tempCurr = tempCurr -> next;
            curr = curr -> next;
        }
        
        // now iterate over the old linked list and copy the random pointers as well 
        curr = head;
        tempCurr = tempHead -> next;
        
        while(curr != NULL) {
            // find the matching for random pointer in hashmap
            Node* nodeMatch = umap[curr -> random];
            
            tempCurr -> random = nodeMatch;
            
            // move both pointers to next node
            tempCurr = tempCurr -> next;
            curr = curr -> next;
        }
        
        return tempHead -> next;
        
    }
};

// tc -> O(n) + O(n) + O(n) -> O(n)
// sc -> O(n)