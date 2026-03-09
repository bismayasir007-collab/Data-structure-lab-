#include <iostream>
using namespace std;

struct Node {
    float rain;
    Node* next;
    Node* prev;
};

int main() {
    Node *head = NULL, *temp, *newNode;

    float total = 0;
    float highest, lowest;
    int highDay = 1, lowDay = 1;

    // Creating doubly linked list for 7 days
    for (int i = 1; i <= 7; i++) {
        float value;

        // Input validation
        do {
            cout << "Enter rainfall for Day " << i << ": ";
            cin >> value;
            if (value < 0)
                cout << "Invalid input! Rainfall cannot be negative."<<endl;
        } while (value < 0);

        newNode = new Node;
        newNode->rain = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
            highest = lowest = value;
        }
        else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;

            if (value > highest) {
                highest = value;
                highDay = i;
            }

            if (value < lowest) {
                lowest = value;
                lowDay = i;
            }
        }

        total += value;
    }

    float average = total / 7;

    cout << "\nTotal Rainfall: " << total << endl;
    cout << "Average Rainfall: " << average << endl;
    cout << "Highest Rainfall: Day " << highDay << " (" << highest << ")"<<endl;
    cout << "Lowest Rainfall: Day " << lowDay << " (" << lowest << ")"<<endl;

    // Finding rainfall after 5th node
    temp = head;
    for (int i = 1; i < 5; i++) {
        temp = temp->next;
    }

    if (temp->next != NULL)
        cout << "Rainfall after 5th node (Day 6): " << temp->next->rain << endl;
    else
        cout << "No node after 5th node."<<endl;

    return 0;
}