class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* beforeDummy = new ListNode(0);
        ListNode* afterDummy = new ListNode(0);

        ListNode* before = beforeDummy;
        ListNode* after = afterDummy;

        while(head != NULL) {
            if(head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }

        after->next = NULL;  // important
        before->next = afterDummy->next;

        return beforeDummy->next;
    }
};