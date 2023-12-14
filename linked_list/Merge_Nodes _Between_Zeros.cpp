// https://leetcode.com/problems/merge-nodes-in-between-zeros/

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

class Solution
{
public:
    void helper(ListNode *&node)
    {
        if (node->next == NULL)
        {
            node = node->next;
            return;
        }
        else if (node->val == 0)
        {
            node = node->next;
            return helper(node);
        }
        else if (node->next->val == 0)
            return helper(node->next);
        node->next->val += node->val;
        node = node->next;
        return helper(node);
    }
    ListNode *mergeNodes(ListNode *head)
    {
        this->helper(head);
        return head;
    }
};