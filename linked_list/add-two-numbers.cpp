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
    ListNode *helper(ListNode *first, ListNode *second, ListNode *&new_head, ListNode *&new_tail, int &temp)
    {
        if (second == NULL && first != NULL)
        {
            second = new ListNode(0);
            return helper(first, second, new_head, new_tail, temp);
        }
        else if (first == NULL && second != NULL)
        {
            first = new ListNode(0);
            return helper(first, second, new_head, new_tail, temp);
        }
        else if (first == NULL && second == NULL)
            return new_head;
        else
        {
            int sum = first->val + second->val;
            sum = sum + temp;
            temp = 0;
            if (new_head == NULL)
            {
                if (sum <= 9)
                {

                    ListNode *new_node = new ListNode(sum);
                    new_head = new_node;
                    new_tail = new_node;
                }
                else
                {
                    ListNode *new_node = new ListNode(sum % 10);
                    new_head = new_node;
                    new_tail = new_node;
                    temp = sum / 10;
                }
            }
            else
            {
                if (sum <= 9)
                {
                    ListNode *new_node = new ListNode(sum);
                    new_tail->next = new_node;
                    new_tail = new_tail->next;
                }
                else
                {
                    ListNode *new_node = new ListNode(sum % 10);
                    new_tail->next = new_node;
                    new_tail = new_tail->next;
                    temp = sum / 10;
                }
            }
        }
        return helper(first->next, second->next, new_head, new_tail, temp);
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL;
        ListNode *tail = NULL;
        int temp = 0;
        ListNode *result = this->helper(l1, l2, head, tail, temp);
        if (temp != 0)
            tail->next = new ListNode(temp);
        return result;
    }
};