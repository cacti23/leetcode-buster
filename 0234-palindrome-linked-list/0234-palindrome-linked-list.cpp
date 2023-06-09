/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // use array data structure
        vector<int> arr;
        
        // copy element into array 
        ListNode* curr = head;
        while(curr != NULL) {
            arr.push_back(curr -> val);
            curr = curr -> next;
        }
        
        // now check if the array is palindrome or not 
        int n = arr.size();
        for(int i = 0; i < n / 2; i++) {
            if(arr[i] != arr[n - i - 1]) return false;
        }
        
        return true;
    }
};

// tc -> O(n) + O(n)
// sc -> O(n)