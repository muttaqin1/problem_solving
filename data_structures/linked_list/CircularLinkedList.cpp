#include <iostream>
using namespace std;
class Node {
public:
  int key = 0;
  int data = 0;
  Node *next = nullptr;
  Node() = default;
  Node(int key, int data) {
    this->key = key;
    this->data = data;
    this->next = nullptr;
  }
  ~Node() {
    cout << "Destructure called" << endl;
    delete next;
    this->next = nullptr;
  }
};

class CircularLinkedList {
private:
  Node *head = nullptr;
  Node *ExistsNode(int key) {
    Node *temp = nullptr;
    Node *pointer = this->head;

    do {
      if (pointer->key == key) {
        temp = pointer;
        break;
      }
      pointer = pointer->next;
    } while (pointer != this->head);
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
    do {
      ++count;
      pointer = pointer->next;
    } while (pointer != this->head);
    return count;
  }

public:
  CircularLinkedList() = default;
  void DisplayNode() {
    if (this->head == nullptr)
      return;
    Node *pointer = this->head;
    do {
      cout << "KEY: " << pointer->key << " "
           << "DATA: " << pointer->data << " "
           << "Address: " << pointer << " "
           << "NEXT: " << pointer->next << " " << this->IsHead(pointer) << endl;
      pointer = pointer->next;
    } while (pointer != this->head);
  }
  void AppendNode(int key, int data) {
    if (this->head != nullptr) {
      if (this->ExistsNode(key) != nullptr) {
        cout << "A node already exists with this key" << endl;
        return;
      }
    }
    Node *node = new Node(key, data);
    if (this->head == nullptr) {
      node->next = node;
      this->head = node;
      cout << "Node appended at the position of head" << endl;
      return;
    }
    Node *pointer = this->head;
    while (pointer->next != this->head) {
      pointer = pointer->next;
    }
    pointer->next = node;
    node->next = this->head;
    cout << "Node Appended" << endl;
  }
  void ReverseNode() {
    if (this->Count() < 2) {
      cout << "Atleast 2 nodes required to reverse the linked list" << endl;
      return;
    }
    Node *prevNode = this->head;
    Node *nextNode = this->head->next;
    while (nextNode != this->head) {
      Node *temp = nextNode->next;
      if (prevNode == this->head) {
        Node *pointer = this->head;
        do {
          pointer = pointer->next;
        } while (pointer->next != this->head);
        prevNode->next = pointer;
      }
      nextNode->next = prevNode;
      prevNode = nextNode;
      nextNode = temp;
    }
    this->head = prevNode;
    cout << "Node reversed" << endl;
  }

  void PrependNode(int key, int data) {
    if (this->head != nullptr) {
      if (this->ExistsNode(key) != nullptr) {
        cout << "A node already exists with this key" << endl;
        return;
      }
    }
    Node *node = new Node(key, data);
    if (this->head == nullptr) {
      node->next = node;
      this->head = node;
      cout << "Node inserted at the position of head" << endl;
      return;
    }
    Node *pointer = this->head;
    do {
      pointer = pointer->next;
    } while (pointer->next != this->head);
    pointer->next = node;
    node->next = this->head;
    this->head = node;
    cout << "Node inserted" << endl;
  }
  void InsertNode(int index, int key, int data) {
    if (this->head == nullptr) {
      cout << "head is empty" << endl;
      return;
    }
    Node *exists = this->ExistsNode(index);
    if (exists == nullptr) {
      cout << "No node exists with this index" << endl;
      return;
    }
    if (this->ExistsNode(key) != nullptr) {
      cout << "A node already exists in this key" << endl;
      return;
    }
    Node *node = new Node(key, data);
    if (exists->next == this->head) {
      node->next = this->head;
      exists->next = node;
      cout << "Node inserted" << endl;
    } else {
      node->next = exists->next;
      exists->next = node;
      cout << "Node inserted" << endl;
    }
  }
  void DeleteNode(int key) {
    if (this->head == nullptr) {
      cout << "Head is null" << endl;
      return;
    }
    Node *exists = this->ExistsNode(key);
    if (exists == nullptr) {
      cout << "No node exists with this key" << endl;
      return;
    }

    if (this->head->key == key) {

      if (this->head->next == this->head) {
        this->head = nullptr;
        cout << "Node unlinked" << endl;
      } else {
        Node *pointer = this->head;
        do {
          pointer = pointer->next;
        } while (pointer->next != this->head);
        pointer->next = pointer->next->next;
        this->head = this->head->next;
        cout << "Node unlinked" << endl;
      }
    } else {
      Node *currNode = this->head;
      Node *nextNode = this->head->next;
      do {
        if (nextNode == exists) {
          break;
        } else {
          currNode = currNode->next;
          nextNode = nextNode->next;
        }
      } while (nextNode->next != this->head);
      if (nextNode != nullptr) {
        currNode->next = nextNode->next;
        cout << "Node unlinked" << endl;
      }
    }
  }
};

int main() {
  CircularLinkedList CLL;
  CLL.AppendNode(1, 10);
  CLL.AppendNode(2, 20);
  CLL.ReverseNode();
  CLL.ReverseNode();
  CLL.DisplayNode();
  return 0;
}
