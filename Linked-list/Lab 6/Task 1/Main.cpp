#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
using namespace std;

int main() {
    LinkedList list;
    int choice, val, target;

    cout << "=== LINKED LIST TEST PROGRAM ===" << endl;

    do {
        cout << "\n1. Push (insert at beginning)" << endl;
        cout << "2. Insert after a value" << endl;
        cout << "3. Delete a value" << endl;
        cout << "4. Pop (remove from beginning)" << endl;
        cout << "5. Display list" << endl;
        cout << "6. Check if empty" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.push(val);
                break;
            case 2:
                cout << "Enter value after which to insert: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> val;
                list.insertAfter(target, val);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                list.deleteVal(val);
                break;
            case 4:
                list.pop();
                break;
            case 5:
                list.display();
                break;
            case 6:
                if (list.isEmpty())
                    cout << "List is empty." << endl;
                else
                    cout << "List is not empty." << endl;
                break;
            case 7:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 7);

    return 0;
}