/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <cmath>

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return NULL;
        ListNode *node = head;
        int start = 0;
        int end = 0;
        while (node->next) {
            ++end;
            node = node->next;
        }
        return buildBST(start, end, &head);
    }
    
    TreeNode* buildBST(int start, int end, ListNode **headRef) {
        if (start > end)
            return NULL;
        
        TreeNode *node = new TreeNode(0);
        int mid = (start + end) / 2;
        
        node->left = buildBST(start, mid - 1, headRef);

        node->val = (*headRef)->val;
        *headRef = (*headRef)->next;
        
        node->right = buildBST(mid + 1, end, headRef);
        
        return node;
    }
};
