class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* temp;
    
            while(curr != NULL){
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            head = prev;
            return head;
        }
    };