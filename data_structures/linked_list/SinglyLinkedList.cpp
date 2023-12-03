#include <cstdlib>
#include <iostream>
using namespace std;

class Node
{
public:
  int key = 0;
  int data = 0;
  Node *next = nullptr;
  Node() = default;
  Node(int key, int data)
  {
    this->key = key;
    this->data = data;
    this->next = nullptr;
  }
  ~Node()
  {
    cout << "Destructure called" << endl;
    delete next;
    this->next = nullptr;
  }
};

class SinglyLinkedList
{
private:
  Node *ExistsNode(int key)
  {
    Node *pointer = this->head;
    Node *temp = nullptr;
    while (pointer != nullptr)
    {
      if (pointer->key == key)
      {
        temp = pointer;
        break;
      }
      pointer = pointer->next;
    }
    return temp;
  };
  string IsHead(Node *ptr)
  {
    if (this->head == ptr)
    {
      return "(HEAD)";
    }
    else
    {
      return "";
    }
  };
  int Count()
  {
    Node *pointer = this->head;
    int count = 0;
    while (pointer != nullptr)
    {
      ++count;
      pointer = pointer->next;
    }
    return count;
  }
  Node *_reverse_node_helper(Node *ptr)
  {
    if (!ptr->next)
    {
      this->head->next = nullptr;
      this->head = ptr;
      return ptr;
    }
    return _reverse_node_helper(ptr->next)->next = ptr;
  }

public:
  Node *head = nullptr;
  SinglyLinkedList() = default;
  void AppendNode(int key, int data)
  {
    if (this->ExistsNode(key) != nullptr)
    {
      cout << "A node already exists with this key" << endl;
      return;
    }
    Node *node = new Node(key, data);
    if (this->head == nullptr)
    {
      this->head = node;
      cout << "Node appended at position head" << endl;
    }
    else
    {
      Node *pointer = this->head;
      while (pointer->next != nullptr)
      {
        pointer = pointer->next;
      }
      pointer->next = node;
      cout << "Node appended" << endl;
    }
  };
  void DisplayNode()
  {
    Node *pointer = this->head;
    while (pointer != nullptr)
    {
      cout << "KEY: " << pointer->key << " "
           << "DATA: " << pointer->data << " "
           << "Address: " << pointer << " "
           << "NEXT: " << pointer->next << " " << this->IsHead(pointer) << endl;
      pointer = pointer->next;
    }
    delete pointer;
  }

  void reverse_node()
  {
    this->_reverse_node_helper(this->head);
  }
  void PrependNode(int key, int data)
  {
    if (this->ExistsNode(key) != nullptr)
    {
      cout << "A node already exists with this key" << endl;
      return;
    }
    Node *node = new Node(key, data);
    node->next = this->head;
    this->head = node;
    cout << "Node prepended" << endl;
  }
  void InsertNode(int index, int key, int data)
  {
    Node *idx = this->ExistsNode(index);
    if (idx == nullptr)
    {
      cout << "No node exists with this index" << endl;
      return;
    }
    if (this->ExistsNode(key) != nullptr)
    {
      cout << "A node already exists with this key" << endl;
      return;
    }
    Node *node = new Node(key, data);
    if (idx->next == nullptr)
    {
      idx->next = node;
      cout << "Node inserted" << endl;
      return;
    }
    node->next = idx->next;
    idx->next = node;
    cout << "Node inserted" << endl;
  }
  void DeleteNode(int key)
  {
    Node *index = this->ExistsNode(key);
    if (index == nullptr)
    {
      cout << "No node exists with this index" << endl;
      return;
    }
    if (this->head == nullptr)
    {
      cout << "Head is null" << endl;
      return;
    }
    if (this->head->key == key)
    {
      if (this->head->next == nullptr)
      {
        this->head = nullptr;
        cout << "Node unlinked head is null" << endl;
      }
      else
      {
        this->head = this->head->next;
        cout << "Node unlinked" << endl;
      }
      return;
    }
    Node *prevNode = this->head;
    Node *nextNode = this->head->next;
    while (nextNode != nullptr)
    {
      if (nextNode == index)
      {
        break;
      }
      else
      {
        prevNode = prevNode->next;
        nextNode = nextNode->next;
      }
    }
    prevNode->next = nextNode->next;
    cout << "Node unlinked" << endl;
  }
  void UpdateNode(int key, int data)
  {
    Node *index = this->ExistsNode(key);
    if (index == nullptr)
    {
      cout << "No node exists with this key" << endl;
      return;
    }
    index->data = data;
    cout << "Node updated" << endl;
  }
};

int main()
{
  SinglyLinkedList sll;
  sll.AppendNode(1, 10);
  sll.AppendNode(2, 20);
  sll.AppendNode(3, 30);
  sll.AppendNode(4, 40);
  sll.AppendNode(5, 50);
  sll.AppendNode(6, 60);
  sll.reverse_node();
  sll.DisplayNode();
  return 0;
}
