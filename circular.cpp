#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node *head = NULL, *temp = NULL, *newNode;

void create() {
    int n, value;
    cout << "Number of Nodes in Linked List: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Enter Data for Node " << i+1 << ": ";
        cin >> value;
        newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = temp = newNode;
            head->next = head;   // ✅ CHANGE: Make first node point to itself (circular link)
        } else {
            temp->next = newNode;
            newNode->next = head; // ✅ CHANGE: Last node always points to head
            temp = newNode;
        }
    }
    cout << "Circular Linked List Created Successfully\n";
}

void insertAtbeginning() {
    int value;
    cout << "Enter Data for New Node: ";
    cin >> value;
    newNode = new Node();
    newNode->data = value;

    if(head == NULL) {
        head = newNode;
        head->next = head;  // ✅ CHANGE: Single node points to itself
    } else {
        temp = head;
        while(temp->next != head) temp = temp->next; // ✅ CHANGE: Traverse until last node
        newNode->next = head; // ✅ CHANGE: New node points to old head
        head = newNode;       // ✅ CHANGE: Update head pointer
        temp->next = newNode; // ✅ CHANGE: Last node points to new head
    }
    cout << "Node Inserted at Beginning\n";
}

void insertAtend() {
    int value;
    cout << "Enter Data for New Node: ";
    cin >> value;
    newNode = new Node();
    newNode->data = value;

    if(head == NULL) {
        head = newNode;
        head->next = head;  // ✅ CHANGE: Point to itself
    } else {
        temp = head;
        while(temp->next != head) temp = temp->next; // ✅ CHANGE: Find last node
        temp->next = newNode;
        newNode->next = head; // ✅ CHANGE: Maintain circular nature
    }
    cout << "Node Inserted at End\n";
}

void insertAtpos() {
    int value, pos;
    cout << "Enter Value for New Node: ";
    cin >> value;
    cout << "Enter Position: ";
    cin >> pos;

    newNode = new Node();                                                                                                                                              
    newNode->data = value;

    if(pos == 1) {
        insertAtbeginning(); // ✅ CHANGE: Reuse already circular logic
        return;
    }

    temp = head;
    for(int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;  // ✅ CHANGE: Point new node correctly
    temp->next = newNode;        // ✅ CHANGE: Insert node in between
    cout << "Node Inserted at Position " << pos << endl;
}

void deleteFirst() {
    if(head == NULL) {
        cout << "List is Empty\n";
        return;
    }
    if(head->next == head) { // ✅ CHANGE: Only one node
        delete head;
        head = NULL;
    } else {
        temp = head;
        Node *del = head;
        while(temp->next != head) temp = temp->next; // ✅ CHANGE: Find last node
        head = head->next;  // ✅ CHANGE: Move head to next
        temp->next = head;  // ✅ CHANGE: Last node points to new head
        delete del;
    }
    cout << "First Node Deleted\n";
}

void deleteEnd() {
    if(head == NULL) {
        cout << "List is Empty\n";
        return;
    }
    if(head->next == head) { // ✅ CHANGE: Only one node
        delete head;
        head = NULL;
    } else {
        Node *prev = NULL;
        temp = head;
        while(temp->next != head) { // ✅ CHANGE: Traverse circular list
            prev = temp;
            temp = temp->next;
        }
        prev->next = head; // ✅ CHANGE: Second last node points to head
        delete temp;
    }
    cout << "Last Node Deleted\n";
}

void deleteAtPosition() {
    int pos;
    cout << "Enter Position to Delete: ";
    cin >> pos;

    if(pos == 1) {
        deleteFirst(); // ✅ CHANGE: Already circular logic
        return;
    }

    if(head == NULL) {
        cout << "List is Empty\n";
        return;
    }

    Node *prev = NULL;
    temp = head;
    int i;
    for(i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if(i < pos || pos < 1) {
        cout << "Position out of range!\n";
        return;
    }

    prev->next = temp->next; // ✅ CHANGE: Bypass node
    delete temp;
    cout << "Node Deleted from Position " << pos << endl;
}

void display() {
    if(head == NULL) {
        cout << "List is Empty\n";
        return;
    }
    temp = head;
    cout << "Circular Linked List: ";
    do {                               // ✅ CHANGE: Use do-while to handle circular traversal
        cout << temp->data << " -> ";
        temp = temp->next;
    } while(temp != head);
    cout << "(head)\n";
}

int main() {
    create();
    display();
    insertAtbeginning();
    display();
    insertAtend();
    display();
    insertAtpos();
    display();
    deleteFirst();
    display();
    deleteEnd();
    display();
    deleteAtPosition();
    display();
    return 0;
}
