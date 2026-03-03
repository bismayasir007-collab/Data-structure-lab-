#include <iostream>
using namespace std;

struct Node {
    string username;
    string fullName;
    int age;
    string bio;
    Node* next;
};

Node* head = NULL;

// Create Profile
void createProfile() {
    Node* newNode = new Node;

    cout << "Enter Username: ";
    cin >> newNode->username;

    cout << "Enter Full Name: ";
    cin.ignore();
    getline(cin, newNode->fullName);

    cout << "Enter Age: ";
    cin >> newNode->age;

    cout << "Enter Bio: ";
    cin.ignore();
    getline(cin, newNode->bio);

    newNode->next = head;
    head = newNode;

    cout << "Profile Created Successfully!\n";
}

// Search Profile
Node* searchProfile(string username) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->username == username) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Update Profile
void updateProfile() {
    if (head == NULL) {
        cout << "No profiles available!\n";
        return;
    }

    string username;
    cout << "Enter Username to update: ";
    cin >> username;

    Node* profile = searchProfile(username);

    if (profile == NULL) {
        cout << "Profile not found!\n";
        return;
    }

    cout << "Enter New Full Name: ";
    cin.ignore();
    getline(cin, profile->fullName);

    cout << "Enter New Age: ";
    cin >> profile->age;

    cout << "Enter New Bio: ";
    cin.ignore();
    getline(cin, profile->bio);

    cout << "Profile Updated Successfully!\n";
}

// Delete Profile
void deleteProfile() {
    if (head == NULL) {
        cout << "No profiles available!\n";
        return;
    }

    string username;
    cout << "Enter Username to delete: ";
    cin >> username;

    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->username == username) {
        head = temp->next;
        delete temp;
        cout << "Profile Deleted Successfully!\n";
        return;
    }

    while (temp != NULL && temp->username != username) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Profile not found!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Profile Deleted Successfully!\n";
}

// View All Profiles
void viewProfiles() {
    if (head == NULL) {
        cout << "No profiles available!\n";
        return;
    }

    Node* temp = head;

    cout << "\n------ All Profiles ------\n";

    while (temp != NULL) {
        cout << "Username: " << temp->username << endl;
        cout << "Full Name: " << temp->fullName << endl;
        cout << "Age: " << temp->age << endl;
        cout << "Bio: " << temp->bio << endl;
        cout << "--------------------------\n";
        temp = temp->next;
    }
}

int main() {
    int choice;

    do {
        cout << "\n1. Create Profile";
        cout << "\n2. Update Profile";
        cout << "\n3. Delete Profile";
        cout << "\n4. Search Profile";
        cout << "\n5. View All Profiles";
        cout << "\n6. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                createProfile();
                break;
            case 2:
                updateProfile();
                break;
            case 3:
                deleteProfile();
                break;
            case 4: {
                string username;
                cout << "Enter Username to search: ";
                cin >> username;
                Node* result = searchProfile(username);
                if (result == NULL)
                    cout << "Profile not found!\n";
                else {
                    cout << "Profile Found:\n";
                    cout << "Full Name: " << result->fullName << endl;
                    cout << "Age: " << result->age << endl;
                    cout << "Bio: " << result->bio << endl;
                }
                break;
            }
            case 5:
                viewProfiles();
                break;
            case 6:
                cout << "Exiting Program...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}