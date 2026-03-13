#include <iostream>
using namespace std;

//  Node class template

template <class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T x) {
        data = x;
        next = nullptr;
    }
};

//  SortedLinkedList class template

template <class T>
class SortedLinkedList {
private:
    Node<T>* head;

public:
    SortedLinkedList() {
        head = nullptr;
    }

    //  INSERTION  (always maintains sorted order)

    // Insert at Start — only if value is smallest (sorted)
    void insertAtStart(T x) {
        Node<T>* newNode = new Node<T>(x);

        if (head == nullptr || x <= head->data) {
            newNode->next = head;
            head = newNode;
            cout << "\n[OK] " << x << " inserted at Start.\n";
        } else {
            cout << "\n[WARNING] " << x
                 << " is not the smallest value. "
                    "Inserting at correct sorted position instead.\n";
            delete newNode;
            insertSorted(x);
        }
    }

    // Insert at End — only if value is largest (sorted)
    void insertAtEnd(T x) {
        Node<T>* newNode = new Node<T>(x);

        if (head == nullptr) {
            head = newNode;
            cout << "\n[OK] " << x << " inserted at End.\n";
            return;
        }

        Node<T>* last = head;
        while (last->next != nullptr)
            last = last->next;

        if (x >= last->data) {
            last->next = newNode;
            cout << "\n[OK] " << x << " inserted at End.\n";
        } else {
            cout << "\n[WARNING] " << x
                 << " is not the largest value. "
                    "Inserting at correct sorted position instead.\n";
            delete newNode;
            insertSorted(x);
        }
    }

    // Insert in Middle — inserts at correct sorted position
    void insertAtMiddle(T x) {
        insertSorted(x);
        cout << "\n[OK] " << x << " inserted at sorted Middle position.\n";
    }

    // Core sorted insertion (used internally)
    void insertSorted(T x) {
        Node<T>* newNode = new Node<T>(x);

        if (head == nullptr || x <= head->data) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node<T>* curr = head;
        while (curr->next != nullptr && curr->next->data < x)
            curr = curr->next;

        newNode->next = curr->next;
        curr->next = newNode;
    }

    //  DELETION

    void deleteAtStart() {
        if (head == nullptr) {
            cout << "\n[ERROR] List is empty. Nothing to delete.\n";
            return;
        }
        Node<T>* temp = head;
        cout << "\n[OK] Deleted " << temp->data << " from Start.\n";
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "\n[ERROR] List is empty. Nothing to delete.\n";
            return;
        }
        if (head->next == nullptr) {
            cout << "\n[OK] Deleted " << head->data << " from End.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* curr = head;
        while (curr->next->next != nullptr)
            curr = curr->next;

        cout << "\n[OK] Deleted " << curr->next->data << " from End.\n";
        delete curr->next;
        curr->next = nullptr;
    }

    void deleteAtMiddle(T x) {
        if (head == nullptr) {
            cout << "\n[ERROR] List is empty. Nothing to delete.\n";
            return;
        }
        if (head->data == x) {
            deleteAtStart();
            return;
        }
        Node<T>* curr = head;
        while (curr->next != nullptr && curr->next->data != x)
            curr = curr->next;

        if (curr->next == nullptr) {
            cout << "\n[ERROR] Value " << x << " not found in list.\n";
            return;
        }
        Node<T>* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        cout << "\n[OK] Deleted " << x << " from Middle.\n";
    }

    //  TRAVERSAL

    void traverse() {
        if (head == nullptr) {
            cout << "\n[INFO] List is empty.\n";
            return;
        }
        cout << "\n--- Traversing List ---\n";
        Node<T>* curr = head;
        int index = 0;
        while (curr != nullptr) {
            cout << "  [" << index++ << "] " << curr->data << "\n";
            curr = curr->next;
        }
        cout << "-----------------------\n";
        cout << "Total nodes: " << index << "\n";
    }

    //  SEARCHING

    void search(T x) {
        if (head == nullptr) {
            cout << "\n[INFO] List is empty.\n";
            return;
        }
        Node<T>* curr = head;
        int index = 0;
        bool found = false;

        cout << "\n--- Searching for " << x << " ---\n";
        while (curr != nullptr) {
            if (curr->data == x) {
                cout << "  Found " << x << " at index " << index << "!\n";
                found = true;
            }
            if (curr->data > x) break;
            curr = curr->next;
            index++;
        }
        if (!found)
            cout << "  " << x << " NOT found in the list.\n";
    }

    //  Display (compact one-line view)

    void display() {
        if (head == nullptr) {
            cout << "  [Empty List]\n";
            return;
        }
        Node<T>* curr = head;
        cout << "  List: ";
        while (curr != nullptr) {
            cout << curr->data;
            if (curr->next) cout << " -> ";
            curr = curr->next;
        }
        cout << "\n";
    }

    ~SortedLinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

//  Menu

void printMenu() {
    cout << "\n========================================\n";
    cout << "   SORTED SINGLY LINKED LIST MENU\n";
    cout << "========================================\n";
    cout << "  --- INSERTION ---\n";
    cout << "  1. Insert at Start\n";
    cout << "  2. Insert at Middle (sorted position)\n";
    cout << "  3. Insert at End\n";
    cout << "  --- DELETION ---\n";
    cout << "  4. Delete from Start\n";
    cout << "  5. Delete from Middle (by value)\n";
    cout << "  6. Delete from End\n";
    cout << "  --- OTHER ---\n";
    cout << "  7. Traverse (display all nodes)\n";
    cout << "  8. Search\n";
    cout << "  9. Display List\n";
    cout << "  0. Exit\n";
    cout << "========================================\n";
    cout << "  Enter choice: ";
}

int main() {
    SortedLinkedList<int> list;
    int choice;
    int value;

    cout << "\n*** Menu-Driven Sorted Singly Linked List ***\n";
    cout << "*** Using Class Template (T = int)         ***\n";

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "  Enter value to insert at Start: ";
                cin >> value;
                list.insertAtStart(value);
                list.display();
                break;

            case 2:
                cout << "  Enter value to insert in Middle: ";
                cin >> value;
                list.insertAtMiddle(value);
                list.display();
                break;

            case 3:
                cout << "  Enter value to insert at End: ";
                cin >> value;
                list.insertAtEnd(value);
                list.display();
                break;

            case 4:
                list.deleteAtStart();
                list.display();
                break;

            case 5:
                cout << "  Enter value to delete from Middle: ";
                cin >> value;
                list.deleteAtMiddle(value);
                list.display();
                break;

            case 6:
                list.deleteAtEnd();
                list.display();
                break;

            case 7:
                list.traverse();
                break;

            case 8:
                cout << "  Enter value to search: ";
                cin >> value;
                list.search(value);
                break;

            case 9:
                list.display();
                break;

            case 0:
                cout << "\n  Exiting... Goodbye!\n";
                break;

            default:
                cout << "\n  [ERROR] Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}