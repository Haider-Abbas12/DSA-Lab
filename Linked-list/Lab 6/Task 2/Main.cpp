#include <iostream>
#include "LinkedStr.h"
#include "LinkedStr.cpp"
using namespace std;

int main() {
    LinkedStr list;
    int choice, val, len;

    cout << "=== Linked Structure Driver ===" << endl;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create new list\n";
        cout << "2. Display list\n";
        cout << "3. Remove first element\n";
        cout << "4. Remove last element\n";
        cout << "5. Remove element by value\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter length: ";
                cin >> len;
                list.makeStr(len);
                break;
            case 2:
                list.displayStr();
                break;
            case 3:
                list.removeFirst();
                cout << "First element removed." << endl;
                list.displayStr();
                break;
            case 4:
                list.removeLast();
                cout << "Last element removed." << endl;
                list.displayStr();
                break;
            case 5:
                cout << "Enter value to remove: ";
                cin >> val;
                list.remove(val);
                list.displayStr();
                break;
            case 0:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}