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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head && head -> next == NULL){
            return NULL;
        }
      
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* second = head;
        
        for(int i = 1; i < n; i++){
            second = second -> next;
            }
        
        while(second -> next){
            prev = curr;
            curr = curr -> next;
            second = second -> next;
        }
    
        if(prev == NULL){
            return head -> next;
        }
        prev -> next = curr -> next;
        delete curr;
       
        return head;
    }
};