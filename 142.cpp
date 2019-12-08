/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Floyd's Tortoise and Hare Algorithm
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast and slow and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                // Cycle detected
                // Find its starting node
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        // No cycle was detected:
        return NULL;
    }
};
