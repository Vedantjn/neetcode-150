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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // when list1 is empty then 
        // our output will be same as list2
        if(list1 == NULL) return list2; 

        // when list2 is empty then our output 
        // will be same as list1
        if(list2 == NULL) return list1;

        // pointing list1 and list2 to smallest and greatest one
        if(list1->val > list2->val) std::swap(list1,list2);

        // act as head of resultant merged list
        ListNode* res = list1;

        while(list1 != NULL && list2 != NULL) {
 
            ListNode* temp = NULL;

            while(list1 != NULL && list1->val <= list2->val) {

                temp = list1;//storing last sorted node  
                list1 = list1->next;
            }

            // link previous sorted node with 
            // next larger node in list2
            temp->next = list2;
            std::swap(list1,list2);
        }

        return res;
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Handle the cases where one or both lists are empty
        if (!list1) return list2;
        if (!list2) return list1;

        // Initialize the head of the new list
        ListNode* head = nullptr;
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        // Use a pointer to track the end of the merged list
        ListNode* temp = head;

        // Merge the two lists
        while (list1 && list2) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        // Attach any remaining elements
        if (list1) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        return head;
    }
};
