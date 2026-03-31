#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularList {
private:
    Node* head;

public:
    CircularList() {
        head = NULL;
    }

    // Insert at beginning
    void insertBefore(int value) {
        Node* newNode = new Node;   
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << "Inserted at beginning"<<endl;
    }

    // Insert at end
    void insertAfter(int value) {
        Node* newNode = new Node;
        newNode->data = value;

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
        cout << "Inserted at end"<<endl;
    }

    // Delete node (all cases)
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty"<<endl;
            return;
        }

        Node *curr = head, *prev = NULL;

        // Only one node
        if (head->data == value && head->next == head) {
            delete head;
            head = NULL;
            cout << "Deleted successfully"<<endl;
            return;
        }

        // Delete head
        if (head->data == value) {
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

        // Delete other nodes
        prev = head;
        curr = head->next;

        while (curr != head) {
            if (curr->data == value) {
                prev->next = curr->next;
                delete curr;
                cout << "Deleted successfully"<<endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Value not found"<<endl;
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty"<<endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(head)"<<endl;
    }
};

// Main function
int main() {
    CircularList obj;

    obj.insertBefore(10);
    obj.insertBefore(5);
    obj.insertAfter(20);
    obj.insertAfter(30);

    obj.display();

    obj.deleteNode(5);
    obj.display();

    return 0;
}