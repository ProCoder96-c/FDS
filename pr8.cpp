//Develop a C++ program to implement a class and function template for stack and queue data
//structures. The program should provide generic functionality to allow stack and queue operations
//(push, pop, enqueue, dequeue) for any data type.
#include <iostream>
#include <fstream>
using namespace std;
template <typename T>
class Stack {
    T arr[100];
    int top;
    int capacity=5;
public:
    Stack() { 
        top = -1; 
    }
    void push(T x)
    {
        if(top==capacity-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            top=top+1;
            arr[top]=x;
        }
    }
    void pop()
    {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        else {
            top = top - 1;
        }
    }
    void display()
    {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        else {
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};
template <typename T>
class Queue {
    T arr[100];
    int front=-1, rear=-1, capacity=5;
public:
    void enqueue(T x)
    {
        if(rear==capacity-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        else{
            rear=rear+1;
            arr[rear]=x;
            if(rear==0)
                front=0;
        }
    }
    void dequeue()
    {
        if (front == -1 && rear == -1) {
            cout << "Queue Underflow" << endl;
            return;
        }
        else {
            front = front + 1;
        }
    }
    void display()
    {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        else {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};
template <typename T>
void performOperations() {
    Stack<T> stack;
    Queue<T> queue;
    int choice;
    T value;

    do {
        cout << "\n===== GENERIC STACK & QUEUE MENU =====\n";
        cout << "1. Push (Stack)\n";
        cout << "2. Pop (Stack)\n";
        cout << "3. Display Stack\n";
        cout << "4. Enqueue (Queue)\n";
        cout << "5. Dequeue (Queue)\n";
        cout << "6. Display Queue\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.display();
            break;
        case 4:
            cout << "Enter value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 5:
            queue.dequeue();
            break;
        case 6:
            queue.display();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);
}

int main() {
    int dataTypeChoice;

    cout << "Select Data Type:\n";
    cout << "1. Integer\n";
    cout << "2. Float\n";
    cout << "3. String\n";
    cout << "Enter choice: ";
    cin >> dataTypeChoice;

    switch (dataTypeChoice) {
    case 1:
        performOperations<int>();
        break;
    case 2:
        performOperations<float>();
        break;
    case 3:
        performOperations<string>();
        break;
    default:
        cout << "Invalid data type choice!\n";
    }

    return 0;
}
