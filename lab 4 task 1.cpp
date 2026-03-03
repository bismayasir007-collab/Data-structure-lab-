#include <iostream>
using namespace std;

struct Node {
    string brand;
    int stock;
    float price;
    Node* next;
};

Node* head = NULL;

// Add Mobile
void addMobile() {
    Node* newNode = new Node;

    cout << "Enter Brand Name: ";
    cin >> newNode->brand;

    cout << "Enter Units in Stock: ";
    cin >> newNode->stock;

    cout << "Enter Price: ";
    cin >> newNode->price;

    newNode->next = head;
    head = newNode;

    cout << "Mobile Added Successfully!\n";
}

// Delete Mobile
void deleteMobile() {
    if (head == NULL) {
        cout << "Inventory is empty!\n";
        return;
    }

    string brandName;
    cout << "Enter Brand Name to delete: ";
    cin >> brandName;

    Node* temp = head;
    Node* prev = NULL;

    // If first node matches
    if (temp != NULL && temp->brand == brandName) {
        head = temp->next;
        delete temp;
        cout << "Mobile Deleted Successfully!\n";
        return;
    }

    // Search in remaining list
    while (temp != NULL && temp->brand != brandName) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Mobile Not Found!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Mobile Deleted Successfully!\n";
}

// Display Mobiles
void displayMobiles() {
    if (head == NULL) {
        cout << "Inventory is empty!\n";
        return;
    }

    Node* temp = head;

    cout << "\n----- Mobile Inventory -----\n";

    while (temp != NULL) {
        cout << "Brand: " << temp->brand << endl;
        cout << "Stock: " << temp->stock << endl;
        cout << "Price: " << temp->price << endl;
        cout << "----------------------------\n";
        temp = temp->next;
    }
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Mobile";
        cout << "\n2. Delete Mobile";
        cout << "\n3. Display Mobiles";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addMobile();
                break;
            case 2:
                deleteMobile();
                break;
            case 3:
                displayMobiles();
                break;
            case 4:
                cout << "Exiting Program...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}