#include <iostream>
using namespace std;

// Inventory Class
class Inventory {
private:
    int serialNum;
    int manufactYear;
    int lotNum;

public:
    // Setter
    void setData(int s, int y, int l) {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }

    // Display
    void display() {
        cout << "Serial Number: " << serialNum << endl;
        cout << "Manufacture Year: " << manufactYear << endl;
        cout << "Lot Number: " << lotNum << endl;
        cout << "----------------------\n";
    }
};

// Node for Linked List
class Node {
public:
    Inventory data;
    Node* next;

    Node(Inventory obj) {
        data = obj;
        next = NULL;
    }
};

// Stack Class (Linked List)
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push
    void push(Inventory obj) {
        Node* newNode = new Node(obj);
        newNode->next = top;
        top = newNode;
        cout << "Part added to inventory"<<endl;
    }

    // Pop
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty"<<endl;
            return;
        }

        Node* temp = top;
        cout << "\nRemoved Part Details:\n";
        temp->data.display();

        top = top->next;
        delete temp;
    }

    // Display all remaining parts
    void display() {
        if (top == NULL) {
            cout << "No items in inventory"<<endl;
            return;
        }

        Node* temp = top;
        cout << "\nRemaining Inventory:\n";

        while (temp != NULL) {
            temp->data.display();
            temp = temp->next;
        }
    }
};

// Main Program
int main() {
    Stack s;
    int choice;

    do {
        cout << "\n1. Add Part\n";
        cout << "2. Remove Part\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Inventory obj;
            int serial, year, lot;

            cout << "Enter Serial Number: ";
            cin >> serial;
            cout << "Enter Manufacture Year: ";
            cin >> year;
            cout << "Enter Lot Number: ";
            cin >> lot;

            obj.setData(serial, year, lot);
            s.push(obj);
        }
        else if (choice == 2) {
            s.pop();
        }

    } while (choice != 3);

    // Display remaining items
    s.display();

    return 0;
}