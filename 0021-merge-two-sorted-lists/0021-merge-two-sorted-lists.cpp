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
        if(!list1) return list2;
         if(!list2) return list1;
        
        ListNode* ptr3 = new ListNode();
        ListNode* head = ptr3;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        
        while (ptr1 && ptr2) {
            if (ptr1->val < ptr2->val) {
                ptr3->val = ptr1->val; 
                ptr1 = ptr1->next;
            } else {
               ptr3->val = ptr2->val; 
                ptr2 = ptr2->next;
                
            }
            
            ptr3->next = new ListNode();
            ptr3 = ptr3-> next;
        }

        if(ptr1){
            while (ptr1) {
                ptr3->val = ptr1->val; 
                ptr1 = ptr1->next;
                if(ptr1 == NULL) ptr3->next = NULL;
                else{
                    ptr3->next = new ListNode();
                    ptr3 = ptr3-> next;
                }
            }
        }
       

        if(ptr2){
            while (ptr2) {
                ptr3->val = ptr2->val; 
                ptr2 = ptr2->next;
                if(ptr2 == NULL) ptr3->next = NULL;
                else{
                    ptr3->next = new ListNode();
                    ptr3 = ptr3-> next;
                }
            }
        }

      
        return head;
    }
};