class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode * curr = head;
        ListNode * prev = nullptr , * next = nullptr;

        while(curr) {

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        } 
        
        head = prev;
        return head;
    }
};