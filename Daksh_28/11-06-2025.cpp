// LeetCode 237
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
    void deleteNode(ListNode* node) {
        if(node == NULL || node->next == NULL) return;
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
// S.C: O(1)
// T.C: O(1)