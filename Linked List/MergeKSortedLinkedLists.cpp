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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<lists.size(); i++)
        {
            while(lists[i]!= NULL)
            {
                pq.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }

        ListNode* current = new ListNode(0);
        ListNode* dummyHead = current;

        while(!pq.empty())
        {
            current->next = new ListNode(pq.top());
            pq.pop();
            current = current->next;
        }

        return dummyHead->next;
    }
};



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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* merged = new ListNode(-1);
        ListNode* mptr = merged;
        ListNode* left = list1;
        ListNode* right = list2;

        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                mptr->next = left;
                mptr = mptr->next;
                left = left->next;
            }
            else{
                mptr->next = right;
                mptr = mptr->next;
                right = right->next;
            }
        }

        if(left != NULL){
            mptr->next = left;
        }

        if(right != NULL){
            mptr->next = right;
        }

        return merged->next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        if(lists.size() == 1){
            return lists[0];
        }
        ListNode* head = lists[0];
        for(int i=1; i<lists.size(); i++){
            head = merge(head, lists[i]);
        }

        return head;
    }
};