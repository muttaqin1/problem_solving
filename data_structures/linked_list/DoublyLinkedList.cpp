#include <iostream>
using namespace std;

class Node {
public:
  int key = 0;
  int data = 0;
  Node *next = nullptr;
  Node *prev = nullptr;
  Node() = default;
  Node(int key, int data) {
    this->key = key;
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoublyLinkedList {
private:
  Node *ExistsNode(int key) {
    Node *temp = nullptr;
    Node *pointer = this->head;
    while (pointer != nullptr) {
      if (pointer->key == key) {
        temp = pointer;
        break;
      }
      pointer = pointer->next;
    }
    return temp;
  }
  string IsHead(Node *ptr) {
    if (this->head == ptr) {
      return "(HEAD)";
    } else {
      return "";
    }
  };
  int Count() {
    Node *pointer = this->head;
    int count = 0;
    while (pointer != nullptr) {
      ++count;
      pointer = pointer->next;
    }
    return count;
  }

public:
  Node *head = nullptr;
  DoublyLinkedList() = default;
  void DisplayNode() {
    Node *pointer = this->head;
    while (pointer != nullptr) {
      cout << "KEY: " << pointer->key << " "
           << "DATA: " << pointer->data << " "
           << "Address: " << pointer << " "
           << "Previous: " << pointer->prev << " "
           << "NEXT: " << pointer->next << " " << this->IsHead(pointer) << endl;

      pointer = pointer->next;
    }
  }

  void AppendNode(int key, int data) {
    if (this->ExistsNode(key) != nullptr) {
      cout << "A node already exists with this key" << endl;
      return;
    }
    Node *node = new Node(key, data);
    if (this->head == nullptr) {
      this->head = node;
      cout << "Node appended at the position of head" << endl;
    } else {
      Node *pointer = this->head;
      while (pointer->next != nullptr)
        pointer = pointer->next;
      node->prev = pointer;
      pointer->next = node;
      cout << "Node appended" << endl;
    }
  }
  void ReverseNodes() {
    if (this->Count() < 2) {
      cout << "Atleast two node required to reverse the linked list" << endl;
      return;
    }
    Node *prevNode = this->head;
    Node *nextNode = this->head->next;
    while (nextNode != nullptr) {
      Node *temp = nextNode->next;
      if (prevNode == this->head) {
        prevNode->next = nullptr;
      }

      nextNode->next = prevNode;
      prevNode->prev = nextNode;
      prevNode = nextNode;
      nextNode = temp;
    }
    this->head = prevNode;
    this->head->prev = nullptr;
    cout << "Nodes reversed" << endl;
  }
  void InsertNode(int index, int key, int data) {
    Node *exists = this->ExistsNode(index);
    if (exists == nullptr) {
      cout << "No node exists with the index" << endl;
      return;
    }
    if (this->ExistsNode(key) != nullptr) {
      cout << "A node already exists with this key" << endl;
      return;
    }
    Node *node = new Node(key, data);
    if (exists->next == nullptr) {
      node->next = nullptr;
      node->prev = exists;
      exists->next = node;
      cout << "Node inserted" << endl;
    } else {
      node->next = exists->next;
      node->prev = exists;
      exists->next = node;
      cout << "Node inserted" << endl;
    }
  }

  void PrependNode(int key, int data) {
    if (this->ExistsNode(key) != nullptr) {
      cout << "A node already exists with this key" << endl;
      return;
    }
    Node *node = new Node(key, data);
    node->next = this->head;
    this->head->prev = node;
    this->head = node;

    cout << "Node prepended" << endl;
  }
  void DeleteNode(int key) {
    Node *exists = this->ExistsNode(key);
    if (exists == nullptr) {
      cout << "No node exists with this key" << endl;
      return;
    }
    if (exists->next == nullptr) {
      exists->prev->next = nullptr;
      cout << "Node unlinked" << endl;
      return;
    }
    exists->prev->next = exists->next;
    exists->next->prev = exists->prev;
    cout << "Node unlinked" << endl;
  }
};

int main() {
  DoublyLinkedList DLL;
  DLL.AppendNode(1, 10);
  DLL.AppendNode(2, 20);
  DLL.AppendNode(3, 30);
  DLL.AppendNode(4, 40);
  DLL.InsertNode(4, 5, 50);
  DLL.InsertNode(1, 6, 60);
  DLL.DeleteNode(6);
  DLL.DeleteNode(5);
  DLL.DeleteNode(2);
  DLL.DisplayNode();
  return 0;
}
