#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a linked list
Node* createList(int n) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> value;

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Function to display linked list
void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to reverse linked list (simplest)
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {
        Node* next = curr->next; // store next node
        curr->next = prev;       // reverse pointer
        prev = curr;             // move prev forward
        curr = next;             // move curr forward
    }

    return prev; // new head
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = createList(n);

    cout << "\nOriginal Linked List: ";
    display(head);

    head = reverseList(head);

    cout << "Reversed Linked List: ";
    display(head);

    return 0;
}
