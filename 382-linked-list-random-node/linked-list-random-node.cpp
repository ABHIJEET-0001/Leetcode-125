class Solution {
public:
    
    ListNode* head;
    
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        
        int result = head->val;
        ListNode* curr = head;
        int i = 1;
        
        while(curr != NULL) {
            
            if(rand() % i == 0) {
                result = curr->val;
            }
            
            curr = curr->next;
            i++;
        }
        
        return result;
    }
};
