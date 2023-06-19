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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode* odd = head,*even = head->next;
        ListNode* even_ = even;
        
        while(odd->next && even->next){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        
        odd->next = even_;
        
        return head;
        
//         if(!head || !head -> next) return head;
        
//         ListNode* odd = head;
//         ListNode* even = head -> next;
//         ListNode* evenStart = even;
        
//         while(odd-> next && even -> next){
            
//             odd -> next = even ->next;
//             odd = odd->next;
//             even -> next = odd -> next;
//             even = odd->next;
//         }
        
//         odd -> next = evenStart;
        
// //         if(even -> next != NULL){
// //             even -> next == NULL;
// //         }
        
//         return head;
    }
        
    
};