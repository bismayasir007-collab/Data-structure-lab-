#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements:";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int choice;
    cout << "--MENU--";
    cout << "1. Linear Search";
    cout << "2. Update Value at Index";
    cout << "3. Reverse Array";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int key, index = -1;
        cout << "Enter element to search: ";
        cin >> key;

        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                index = i;
                break;
            }
        }

        if (index != -1)
            cout << "Element found at index: " << index;
        else
            cout << "Element not found";
    }

    else if (choice == 2) {
        int index, newValue;
        cout << "Enter index to update: ";
        cin >> index;

        if (index >= 0 && index < n) {
            cout << "Enter new value: ";
            cin >> newValue;
            arr[index] = newValue;

            cout << "Updated Array:";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
        } else {
            cout << "Invalid index!";
        }
    }

    else if (choice == 3) {
        for (int i = 0; i < n / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = temp;
        }

        cout << "Reversed Array:";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }

    else {
        cout << "Invalid choice!";
    }

    return 0;
}
