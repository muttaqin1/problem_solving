#include <cstdlib>
#include <iostream>
using namespace std;

class Node
{
public:
  int data = 0;
  Node *next = nullptr;
  Node() = default;
  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
  }
};

class SinglyLinkedList
{
private:
  Node *_exists_node_helper(Node *node, int index)
  {
    if (node == nullptr)
      return node;
    else if (index == 0)
      return node;
    else
      return _exists_node_helper(node->next, index - 1);
  }
  Node *_insert_node_helper(Node *node, Node *new_node, int index)
  {
    if (node == nullptr)
      return node;
    else if (index == 0)
    {
      new_node->next = node;
      return new_node;
    }
    node->next = _insert_node_helper(node->next, new_node, index - 1);
    return node;
  }
  string _is_head_or_tail(Node *ptr)
  {
    if (this->head == ptr && this->tail == ptr)
      return "(HEAD & TAIL)";
    else if (this->head == ptr)
      return "(HEAD)";
    else if (this->tail == ptr)
      return "(TAIL)";
    else
      return "";
  };
  int _count_nodes_helper(Node *node)
  {
    if (node == nullptr)
      return 0;
    else
      return 1 + _count_nodes_helper(node->next);
  }

  Node *_reverse_node_helper(Node *ptr)
  {
    if (!ptr->next)
    {
      this->tail = this->head;
      this->head->next = nullptr;
      this->head = ptr;
      return ptr;
    }
    return _reverse_node_helper(ptr->next)->next = ptr;
  }
  Node *_exists_node(int index)
  {
    return this->_exists_node_helper(this->head, index);
  };

  Node *_delete_node_helper(Node *node, int index)
  {
    if (node == nullptr)
      return node;
    else if (index == 0)
      return node->next;
    node->next = _delete_node_helper(node->next, index - 1);
    return node;
  }

public:
  Node *head = nullptr;
  Node *tail = nullptr;
  SinglyLinkedList() = default;
  int size(void)
  {
    return _count_nodes_helper(this->head);
  }
  void append_node(int data)
  {
    if (this->head == nullptr)
      this->head = this->tail = new Node(data);
    else
    {
      this->tail->next = new Node(data);
      this->tail = this->tail->next;
    }
  };
  void display_node()
  {
    Node *pointer = this->head;
    int count = 0;
    while (pointer != nullptr)
    {
      cout << "INDEX: " << count++ << " "
           << "DATA: " << pointer->data << " "
           << "ADDRESS: " << pointer << " "
           << "NEXT: " << pointer->next << " " << this->_is_head_or_tail(pointer) << endl;
      pointer = pointer->next;
    }
    delete pointer;
  }

  void reverse_node()
  {
    this->_reverse_node_helper(this->head);
  }
  void prepend_node(int data)
  {
    Node *node = new Node(data);
    node->next = this->head;
    this->head = node;
    cout << "Node prepended" << endl;
  }
  void insert_node(int index, int data)
  {
    if (this->_exists_node(index) == nullptr)
    {
      cout << "No node exists with this index" << endl;
      return;
    }
    Node *node = new Node(data);
    this->head = this->_insert_node_helper(this->head, node, index);
  }
  void delete_node(int index)
  {
    this->head = this->_delete_node_helper(this->head, index);
  }
  void update_node(int index, int data)
  {
    Node *node = this->_exists_node(index);
    if (node == nullptr)
    {
      cout << "No node exists with this key" << endl;
      return;
    }
    node->data = data;
    cout << "Node updated" << endl;
  }
  void take_input(void)
  {
    cout << "Enter -1 to stop." << endl;
    cout << "Enter data:" << endl;
    while (true)
    {
      int data;
      cin >> data;
      if (data != -1)
        this->append_node(data);
      else
        break;
    }
  }
};

int main()
{
  SinglyLinkedList sll;
  sll.take_input();
  sll.display_node();
  return 0;
}
