#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    if (head == NULL)
    {
        Node *new_node = new Node(val);
        head = new_node;
        tail = new_node;
    }
    else
    {
        Node *new_node = new Node(val);
        new_node->prev = tail;
        tail->next = new_node;
        tail = tail->next;
    }
}
bool is_palindrome(Node *head, Node *tail)
{
    if (head == tail || tail->next == head)
        return true;
    return head->val == tail->val && is_palindrome(head->next, tail->prev);
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    while (true)
    {
        int val;
        cin >> val;
        if (val != -1)
            insert_at_tail(head, tail, val);
        else
            break;
    }
    bool result = is_palindrome(head, tail);
    if (result)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;

    return 0;
}