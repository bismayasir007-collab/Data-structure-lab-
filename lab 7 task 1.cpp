#include <iostream>
using namespace std;

// Node class for Book
class Node {
public:
    string title;
    float price;
    int edition;
    int pages;
    Node* next;

    Node(string t, float p, int e, int pg) {
        title = t;
        price = p;
        edition = e;
        pages = pg;
        next = NULL;
    }
};

// Stack class
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push (insert)
    void push(string t, float p, int e, int pg) {
        Node* newNode = new Node(t, p, e, pg);
        newNode->next = top;
        top = newNode;
        cout << "Book added successfully"<<endl;
    }

    // Pop (delete)
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty"<<endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;

        cout << "Book removed successfully"<<endl;
    }

    // Peek (top element)
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty"<<endl;
            return;
        }

        cout << "\nTop Book: /n";
        cout << "Title: " << top->title << endl;
        cout << "Price: " << top->price << endl;
        cout << "Edition: " << top->edition << endl;
        cout << "Pages: " << top->pages << endl;
    }

    // Display all books
    void display() {
        if (top == NULL) {
            cout << "Stack is empty"<<endl;
            return;
        }

        Node* temp = top;
        cout << "\nRemaining Books in Stack:\n";

        while (temp != NULL) {
            cout << "-------------------\n";
            cout << "Title: " << temp->title << endl;
            cout << "Price: " << temp->price << endl;
            cout << "Edition: " << temp->edition << endl;
            cout << "Pages: " << temp->pages << endl;
            temp = temp->next;
        }
    }
};

// Main function
int main() {
    Stack s;

    // 1. Push 5 books
    s.push("Book1", 500, 1, 200);
    s.push("Book2", 600, 2, 250);
    s.push("Book3", 700, 3, 300);
    s.push("Book4", 800, 2, 350);
    s.push("Book5", 900, 1, 400);

    // 2. Peek top book
    s.peek();

    // 3. Pop 2 books
    s.pop();
    s.pop();

    // 4. Display remaining books
    s.display();

    return 0;
}