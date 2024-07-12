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
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next)) return; 

        ListNode* dummy = head;
        stack<ListNode*>st;

        while(dummy){
            st.push(dummy);
            dummy=dummy->next;
        }
        int size=st.size();
        dummy = head;

        ListNode* temp;

        for(int i=0; i<size/2; i++){
            temp = dummy -> next;
            dummy -> next = st.top();
            st.top()-> next = temp;
            dummy = dummy -> next -> next;
            st.pop();
        }
        dummy->next=NULL;
    }
};