#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    int code;
    float price;
};

int main() {
    int n;

    cout << "Enter number of products: ";
    cin >> n;

    // Dynamic allocation of array of products
    Product* p = new Product[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter details of product " << i + 1 << endl;
        cout << "Name: ";
        cin >> p[i].name;
        cout << "Code: ";
        cin >> p[i].code;
        cout << "Price: ";
        cin >> p[i].price;
    }

    // Display
    cout << "-----Product List------"<<endl;
    for (int i = 0; i < n; i++) {
        cout << "Product " << i + 1 << endl;
        cout << "Name: " << p[i].name << endl;
        cout << "Code: " << p[i].code << endl;
        cout << "Price: " << p[i].price << endl;
    }

    // Free memory
    delete[] p;
    p = nullptr;

    return 0;
}