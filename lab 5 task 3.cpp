#include <iostream>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
    Node* prev;
};

Node* head = NULL;

// Add player in sorted order (ascending score)
void addPlayer(string name, int score) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->score = score;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    if (score < head->score) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    while (temp->next != NULL && temp->next->score < score)
        temp = temp->next;

    newNode->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete player by name
void deletePlayer(string name) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->name == name) {

            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            delete temp;
            cout << "Player deleted"<<endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Player not found"<<endl;
}

// Display all players
void displayList() {
    Node* temp = head;

    cout << "\nPlayers List\n";
    while (temp != NULL) {
        cout << temp->name << " - " << temp->score << endl;
        temp = temp->next;
    }
}

// Display lowest score player
void lowestScore() {
    if (head != NULL)
        cout << "Lowest Score Player: " << head->name << " - " << head->score << endl;
    else
        cout << "List is empty\n";
}

// Display players with same score
void sameScore(int score) {
    Node* temp = head;
    cout << "Players with score " << score << endl;

    while (temp != NULL) {
        if (temp->score == score)
            cout << temp->name << endl;

        temp = temp->next;
    }
}

// Display backward from a player
void displayBackward(string name) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->name == name) {
            temp = temp->prev;

            cout << "Players behind " << name << endl;

            while (temp != NULL) {
                cout << temp->name << " - " << temp->score << endl;
                temp = temp->prev;
            }
            return;
        }
        temp = temp->next;
    }

    cout << "Player not found"<<endl;
}

int main() {

    int choice, score;
    string name;

    do {

        cout << "\n1. Add Player" << endl;
        cout << "2. Delete Player" << endl;
        cout << "3. Display All Players" << endl;
        cout << "4. Display Lowest Score Player" << endl;
        cout << "5. Display Players with Same Score" << endl;
        cout << "6. Display Backward From Player" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter choice: "<<endl;
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter player name: "<<endl;
            cin >> name;
            cout << "Enter score: ";
            cin >> score;
            addPlayer(name, score);
            break;

        case 2:
            cout << "Enter player name to delete: "<<endl;
            cin >> name;
            deletePlayer(name);
            break;

        case 3:
            displayList();
            break;

        case 4:
            lowestScore();
            break;

        case 5:
            cout << "Enter score: "<<endl;
            cin >> score;
            sameScore(score);
            break;

        case 6:
            cout << "Enter player name: "<<endl;
            cin >> name;
            displayBackward(name);
            break;

        }

    } while (choice != 7);

    return 0;
}