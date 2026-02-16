#include <iostream>
using namespace std;

int main() {

    // Allocate memory
    char* ch = new char;

    cout << "Enter a character: ";
    cin >> *ch;

    cout << "Stored character: " << *ch << endl;

    // Free memory
    delete ch;
    ch = nullptr;

    return 0;
}