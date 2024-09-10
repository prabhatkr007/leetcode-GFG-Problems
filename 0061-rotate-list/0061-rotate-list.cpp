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
    ListNode* rotateRight(ListNode* head, int k) {
         if (!head || !head->next || k == 0) return head;

        // Step 1: Find the length of the list
        ListNode* current = head;
        int length = 1;
        while (current->next) {
            current = current->next;
            length++;
        }

        // Step 2: Connect the last node to the head to make it circular
        current->next = head;

        // Step 3: Normalize k
        k = k % length;
        int stepsToNewHead = length - k;

        // Step 4: Find the new head and tail
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }

        // The new head is the next of new tail
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;  // Break the circle

        return newHead;
    }
};