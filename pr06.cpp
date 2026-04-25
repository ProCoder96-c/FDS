//Implement an inventory management system for a shop using C++ that allows performing
//various file handling operations, such as adding new items, updating item details, deleting items,
//and displaying the inventory. The system should store and retrieve inventory data from a file.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    double price;
};

// Function to add a new item
void addItem() {
    ofstream fout("inventory.txt", ios::app);
    Item item;
    cout << "\nEnter Item ID: ";
    cin >> item.id;
    cin.ignore();
    cout << "Enter Item Name: ";
    getline(cin, item.name);
    cout << "Enter Quantity: ";
    cin >> item.quantity;
    cout << "Enter Price: ";
    cin >> item.price;

    fout << item.id << " " << item.name << " " << item.quantity << " " << item.price << endl;
    fout.close();
    cout << "\nItem added successfully!\n";
}

// Function to display all items
void displayItems() {
    ifstream fin("inventory.txt");
    if (!fin) {
        cout << "\nNo inventory file found.\n";
        return;
    }

    Item item;
    cout << "\n--------------------------------------------\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Qty" << setw(10) << "Price\n";
    cout << "--------------------------------------------\n";

    while (fin >> item.id >> item.name >> item.quantity >> item.price) {
        cout << left << setw(10) << item.id
             << setw(20) << item.name
             << setw(10) << item.quantity
             << setw(10) << item.price << endl;
    }

    fin.close();
}

// Function to update an existing item
void updateItem() {
    ifstream fin("inventory.txt");
    ofstream fout("temp.txt");
    if (!fin) {
        cout << "\nNo inventory file found.\n";
        return;
    }

    int id, found = 0;
    Item item;
    cout << "\nEnter Item ID to update: ";
    cin >> id;

    while (fin >> item.id >> item.name >> item.quantity >> item.price) {
        if (item.id == id) {
            found = 1;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, item.name);
            cout << "Enter new quantity: ";
            cin >> item.quantity;
            cout << "Enter new price: ";
            cin >> item.price;
        }
        fout << item.id << " " << item.name << " " << item.quantity << " " << item.price << endl;
    }

    fin.close();
    fout.close();

    remove("inventory.txt");
    rename("temp.txt", "inventory.txt");

    if (found)
        cout << "\nItem updated successfully!\n";
    else
        cout << "\nItem ID not found!\n";
}

// Function to delete an item
void deleteItem() {
    ifstream fin("inventory.txt");
    ofstream fout("temp.txt");
    if (!fin) {
        cout << "\nNo inventory file found.\n";
        return;
    }

    int id, found = 0;
    Item item;
    cout << "\nEnter Item ID to delete: ";
    cin >> id;

    while (fin >> item.id >> item.name >> item.quantity >> item.price) {
        if (item.id != id) {
            fout << item.id << " " << item.name << " " << item.quantity << " " << item.price << endl;
        } else {
            found = 1;
        }
    }

    fin.close();
    fout.close();

    remove("inventory.txt");
    rename("temp.txt", "inventory.txt");

    if (found)
        cout << "\nItem deleted successfully!\n";
    else
        cout << "\nItem ID not found!\n";
}

// Main Menu
int main() {
    int choice;
    do {
        cout << "\n===== INVENTORY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Item";
        cout << "\n2. Display All Items";
        cout << "\n3. Update Item";
        cout << "\n4. Delete Item";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayItems(); break;
            case 3: updateItem(); break;
            case 4: deleteItem(); break;
            case 5: cout << "\nExiting program...\n"; break;
            default: cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
