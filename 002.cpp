#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        } else {
            ListNode* sum = new ListNode(l1->val + l2->val);
            sum->next = addTwoNumbers(l1->next, l2->next);
            for (ListNode* ptr = sum; ptr; ) {
                if (ptr->val >= 10) {
                    ptr->val -= 10;
                    if (!ptr->next) {
                        ptr->next = new ListNode(1);
                    } else {
                        ptr->next->val += 1;
                    }
                }
                ptr = ptr->next;
            }
            return sum;
        }
    }
};

int main() {
    return 0;
}
