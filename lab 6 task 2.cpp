#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* next;
};

class EmployeeList {
private:
    Node* head;

public:
    EmployeeList() {
        head = NULL;
    }

    // Add employee
    void addEmployee(string name) {
        Node* newNode = new Node;
        newNode->name = name;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Added successfully"<<endl;
    }

    // Delete employee
    void deleteEmployee(string name) {
        if (head == NULL) {
            cout << "List is empty"<<endl;
            return;
        }

        Node *curr = head, *prev = NULL;

        // One node
        if (head->name == name && head->next == head) {
            delete head;
            head = NULL;
            cout << "Deleted successfully"<<endl;
            return;
        }

        // Delete head
        if (head->name == name) {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            head = head->next;
            delete curr;
            cout << "Deleted successfully"<<endl;
            return;
        }

        // Delete others
        prev = head;
        curr = head->next;

        while (curr != head) {
            if (curr->name == name) {
                prev->next = curr->next;
                delete curr;
                cout << "Deleted successfully"<<endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Employee not found"<<endl;
    }

    // Search
    void searchEmployee(string name) {
        if (head == NULL) {
            cout << "List is empty"<<endl;
            return;
        }

        Node* temp = head;
        do {
            if (temp->name == name) {
                cout << "Found successfully"<<endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Employee not found"<<endl;
    }

    // Update
    void updateEmployee(string oldName, string newName) {
        if (head == NULL) {
            cout << "List is empty"<<endl;
            return;
        }

        Node* temp = head;
        do {
            if (temp->name == oldName) {
                temp->name = newName;
                cout << "Updated successfully"<<endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Employee not found"<<endl;
    }

    // Display
    void display() {
        if (head == NULL) {
            cout << "List is empty"<<endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(head)"<<endl;
    }
};

// Main
int main() {
    EmployeeList emp;

    emp.addEmployee("Ali");
    emp.addEmployee("Ahmed");
    emp.addEmployee("Sara");

    emp.display();

    emp.searchEmployee("Ahmed");
    emp.updateEmployee("Ahmed", "Ayesha");
    emp.display();

    emp.deleteEmployee("Ali");
    emp.display();

    return 0;
}