#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList {
public:
    Node* head;
    Node* tail;
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    void addNode(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};
Node* patition(Node* head, Node* tail) {
    Node* pivot = head;
    Node* curr = head;
    Node* prev = head;
    while (curr != tail->next) {
        if (curr->data < pivot->data) {
            swap(curr->data, prev->next->data);
            prev = prev->next;
        }
        curr = curr->next;
    }
    swap(pivot->data, prev->data);
    return prev;
}
void quickSort(Node* head, Node* tail) {
    if (head == nullptr || head == tail || head == tail->next) {
        return;
    }
    Node* pivot = patition(head, tail);
    quickSort(head, pivot);
    quickSort(pivot->next, tail);
}
    int main() {
    LinkedList l;
    l.addNode(3);
    l.addNode(1);
    l.addNode(2);
    l.addNode(4);
    l.addNode(6);
    l.addNode(5);
    quickSort(l.head, l.tail);
    l.printList();
    system("pause");
    return 0;
}