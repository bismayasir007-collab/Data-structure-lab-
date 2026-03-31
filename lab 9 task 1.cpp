#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow "<<endl;
            return;
        }

        if (front == -1) front = 0;

        arr[++rear] = value;
        cout << "Enqueued successfully "<<endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow"<<endl;
            return;
        }

        cout << "Dequeued: " << arr[front++] << endl;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty"<<endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " "<<endl;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: "<<endl;
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        }
    } while (choice != 4);

    return 0;
}