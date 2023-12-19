
class Solution
{
public:
    bool helper(ListNode *&head, ListNode *curr)
    {
        if (curr == NULL)
            return true;
        bool aux = helper(head, curr->next);
        if (!aux)
            return aux;
        else
        {
            if (curr->val != head->val)
                return false;
            else
            {
                head = head->next;
                return true;
            }
        }
    }
    bool isPalindrome(ListNode *head)
    {
        return this->helper(head, head);
    }
};
