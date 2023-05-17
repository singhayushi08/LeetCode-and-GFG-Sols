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

ListNode* reverseLL(ListNode* head) {
    ListNode *prev = NULL, *curr = head, *fwd = NULL;
    
    while(curr != NULL) {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    
    return prev;
}

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // now slow is at the end of first half of LL
        ListNode *h2 = slow->next;
        slow->next = NULL; // break the LL
        
        ListNode *newHead = reverseLL(h2);
        
        int max_sum = 0;
        while(head != NULL) {
            int sum = head->val + newHead->val;
            max_sum = max(sum, max_sum);
            head = head->next;
            newHead = newHead->next;
        }
        
        return max_sum;
    }
};