class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prev = &dummy;
        
        while(prev->next && prev->next->next) {
            
            ListNode* first = prev->next;
            ListNode* second = first->next;
            
            // Swapping
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            // Move prev pointer
            prev = first;
        }
        
        return dummy.next;
    }
};
