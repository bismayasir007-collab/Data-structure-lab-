#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Function to create list from user input
void createList() {
    int n, value;
    cout << "Enter number of students: "<<endl;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter marks: "<<endl;
        cin >> value;

        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

// Insert at beginning
void addAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

    head = newNode;
}

// Insert after 45 value
void addAfter45(int value) {
    Node* temp = head;

    while(temp != NULL && temp->data != 45) {
        temp = temp->next;
    }

    if(temp == NULL) {
        cout << "45 not found in list!"<<endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete at beginning
void deleteAtBeginning() {
    if(head == NULL) {
        cout << "List is empty!"<<endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    delete temp;
}

// Delete after 45 value
void deleteAfter45() {
    Node* temp = head;

    while(temp != NULL && temp->data != 45) {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL) {
        cout << "No node exists after 45!"<<endl;
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;

    if(delNode->next != NULL)
        delNode->next->prev = temp;

    delete delNode;
}

// Display list
void display() {
    Node* temp = head;
    cout << "Marks List: "<<endl;
    while(temp != NULL) {
        cout << temp->data << " <-> "<<endl;
        temp = temp->next;
    }
    cout << "NULL"<<endl;
}

// Main function
int main() {
    createList();
    display();

    int choice, value;

    do {
        cout << "\n1. Insert at Beginning"<<endl;
        cout << "\n2. Insert After 45"<<endl;
        cout << "\n3. Delete at Beginning"<<endl;
        cout << "\n4. Delete After 45"<<endl;
        cout << "\n5. Display"<<endl;
        cout << "\n6. Exit"<<endl;
        cout << "\nEnter choice: "<<endl;
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter marks to insert: "<<endl;
                cin >> value;
                addAtBeginning(value);
                break;

            case 2:
                cout << "Enter marks to insert after 45: "<<endl;
                cin >> value;
                addAfter45(value);
                break;

            case 3:
                deleteAtBeginning();
                break;

            case 4:
                deleteAfter45();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Exiting..."<<endl;
                break;

            default:
                cout << "Invalid choice!"<<endl;
        }

    } while(choice != 6);

    return 0;
}