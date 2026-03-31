#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    // Insert at rear
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Inserted successfully "<<endl;
    }

    // Delete from front
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty "<<endl;
            return;
        }

        Node* temp = front;
        cout << "Deleted: " << temp->data << endl;

        front = front->next;

        if (front == NULL) rear = NULL;

        delete temp;
    }

    // Display
    void display() {
        if (front == NULL) {
            cout << "Queue is empty "<<endl;
            return;
        }

        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " -> "<<endl;
            temp = temp->next;
        }
        cout << "NULL "<<endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}