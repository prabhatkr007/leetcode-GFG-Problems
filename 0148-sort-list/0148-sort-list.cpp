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
    ListNode* sortList(ListNode* head) {
        vector<int> sol;
        ListNode* temp = head;
        
        while(temp!=NULL){
            sol.push_back(temp->val);
            temp = temp->next;
        }
        
        sort(sol.begin(), sol.end());
        
        temp=head;
        int n = sol.size();
        for(int i = 0; i < n; i++){
            temp -> val = sol[i];
            temp = temp -> next;
        }
        return head;
    }
};