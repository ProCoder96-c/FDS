#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a linked list
Node* createList(int n) {
    Node* head = NULL;
    Node* temp = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> value;

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to display a linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to concatenate two linked lists
Node* concatenate(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;  // Move to last node of first list
    }
    temp->next = head2; // Link last node of list1 to head of list2

    return head1;
}

int main() {
    int n1, n2;

    cout << "Enter number of nodes in first list: ";
    cin >> n1;
    Node* head1 = createList(n1);

    cout << "Enter number of nodes in second list: ";
    cin >> n2;
    Node* head2 = createList(n2);

    cout << "\nFirst Linked List: ";
    display(head1);

    cout << "Second Linked List: ";
    display(head2);

    head1 = concatenate(head1, head2);

    cout << "\nConcatenated Linked List: ";
    display(head1);

    return 0;
}
