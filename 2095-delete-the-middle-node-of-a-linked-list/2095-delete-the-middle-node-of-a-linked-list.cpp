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
    ListNode* deleteMiddle(ListNode* head) {
       if(head -> next == NULL){
           return NULL;
       }
      
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* fast = head;
        
        while(fast && fast -> next){
            prev = curr;
            curr = curr -> next;
            fast = fast -> next -> next;
        }
        
        prev -> next = curr -> next;
        delete curr;
        
        return head;
        
    }
};