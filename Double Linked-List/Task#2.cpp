#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

//  SortedDoublyLinkedList class template
template <class T>
class SortedDoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    SortedDoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    //  CORE SORTED INSERT  (used internally by all insertions)
    void insertSorted(T x) {
        Node<T>* newNode = new Node<T>(x);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        if (x <= head->data) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        if (x >= tail->data) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            return;
        }

        Node<T>* curr = head->next;
        while (curr != nullptr && curr->data < x)
            curr = curr->next;

        Node<T>* prevNode = curr->prev;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = curr;
        curr->prev = newNode;
    }

    //  INSERTION
    void insertAtStart(T x) {
        if (head == nullptr || x <= head->data) {
            insertSorted(x);
            cout << "\n[OK] " << x << " inserted at Start.\n";
        } else {
            cout << "\n[WARNING] " << x
                 << " is not the smallest value. "
                    "Inserting at correct sorted position instead.\n";
            insertSorted(x);
        }
    }

    void insertAtEnd(T x) {
        if (tail == nullptr || x >= tail->data) {
            insertSorted(x);
            cout << "\n[OK] " << x << " inserted at End.\n";
        } else {
            cout << "\n[WARNING] " << x
                 << " is not the largest value. "
                    "Inserting at correct sorted position instead.\n";
            insertSorted(x);
        }
    }

    void insertAtMiddle(T x) {
        insertSorted(x);
        cout << "\n[OK] " << x << " inserted at sorted Middle position.\n";
    }

    //  DELETION
    void deleteAtStart() {
        if (head == nullptr) {
            cout << "\n[ERROR] List is empty. Nothing to delete.\n";
            return;
        }
        Node<T>* temp = head;
        cout << "\n[OK] Deleted " << temp->data << " from Start.\n";

        if (head == tail) {         
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteAtEnd() {
        if (tail == nullptr) {
            cout << "\n[ERROR] List is empty. Nothing to delete.\n";
            return;
        }
        Node<T>* temp = tail;
        cout << "\n[OK] Deleted " << temp->data << " from End.\n";

        if (head == tail) {         
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void deleteAtMiddle(T x) {
        if (head == nullptr) {
            cout << "\n[ERROR] List is empty. Nothing to delete.\n";
            return;
        }

        Node<T>* curr = head;
        while (curr != nullptr && curr->data != x) {
            if (curr->data > x) break;   
            curr = curr->next;
        }

        if (curr == nullptr || curr->data != x) {
            cout << "\n[ERROR] Value " << x << " not found in list.\n";
            return;
        }

        if (curr == head) {
            deleteAtStart();
            return;
        }
        if (curr == tail) {
            deleteAtEnd();
            return;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        cout << "\n[OK] Deleted " << x << " from Middle.\n";
        delete curr;
    }

    //  TRAVERSAL  (forward and backward)
    void traverseForward() {
        if (head == nullptr) {
            cout << "\n[INFO] List is empty.\n";
            return;
        }
        cout << "\n--- Forward Traversal (Head → Tail) ---\n";
        Node<T>* curr = head;
        int index = 0;
        while (curr != nullptr) {
            cout << "  [" << index++ << "]  data=" << curr->data
                 << "  prev=" << (curr->prev ? to_string(curr->prev->data) : "NULL")
                 << "  next=" << (curr->next ? to_string(curr->next->data) : "NULL")
                 << "\n";
            curr = curr->next;
        }
        cout << "  Total nodes: " << index << "\n";
        cout << "---------------------------------------\n";
    }

    void traverseBackward() {
        if (tail == nullptr) {
            cout << "\n[INFO] List is empty.\n";
            return;
        }
        cout << "\n--- Backward Traversal (Tail → Head) ---\n";
        Node<T>* curr = tail;
        int index = 0;
        while (curr != nullptr) {
            cout << "  [" << index++ << "]  data=" << curr->data
                 << "  next=" << (curr->next ? to_string(curr->next->data) : "NULL")
                 << "  prev=" << (curr->prev ? to_string(curr->prev->data) : "NULL")
                 << "\n";
            curr = curr->prev;
        }
        cout << "  Total nodes: " << index << "\n";
        cout << "----------------------------------------\n";
    }

    //  SEARCHING
    void search(T x) {
        if (head == nullptr) {
            cout << "\n[INFO] List is empty.\n";
            return;
        }
        cout << "\n--- Searching for " << x << " ---\n";
        Node<T>* curr = head;
        int index = 0;
        bool found = false;

        while (curr != nullptr) {
            if (curr->data == x) {
                cout << "  Found " << x << " at index " << index << "\n";
                cout << "  prev = " << (curr->prev ? to_string(curr->prev->data) : "NULL") << "\n";
                cout << "  next = " << (curr->next ? to_string(curr->next->data) : "NULL") << "\n";
                found = true;
            }
            if (curr->data > x) break;  
            curr = curr->next;
            index++;
        }
        if (!found)
            cout << "  " << x << " NOT found in the list.\n";
    }

    //  Display  (compact one-line view, both directions)
    void display() {
        if (head == nullptr) {
            cout << "  [Empty List]\n";
            return;
        }
        cout << "  NULL <-> ";
        Node<T>* curr = head;
        while (curr != nullptr) {
            cout << curr->data;
            if (curr->next) cout << " <-> ";
            curr = curr->next;
        }
        cout << " <-> NULL\n";
    }

    ~SortedDoublyLinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

//  Menu
void printMenu() {
    cout << "\n==============================================\n";
    cout << "   SORTED DOUBLY LINKED LIST MENU\n";
    cout << "==============================================\n";
    cout << "  --- INSERTION ---\n";
    cout << "  1. Insert at Start\n";
    cout << "  2. Insert at Middle (sorted position)\n";
    cout << "  3. Insert at End\n";
    cout << "  --- DELETION ---\n";
    cout << "  4. Delete from Start\n";
    cout << "  5. Delete from Middle (by value)\n";
    cout << "  6. Delete from End\n";
    cout << "  --- OTHER ---\n";
    cout << "  7. Traverse Forward  (Head -> Tail)\n";
    cout << "  8. Traverse Backward (Tail -> Head)\n";
    cout << "  9. Search\n";
    cout << " 10. Display List\n";
    cout << "  0. Exit\n";
    cout << "==============================================\n";
    cout << "  Enter choice: ";
}

int main() {
    SortedDoublyLinkedList<int> list;
    int choice, value;

    cout << "\n*** Menu-Driven Sorted Doubly Linked List ***\n";
    cout << "*** Using Class Template (T = int)          ***\n";

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
                list.traverseForward();
                break;

            case 8:
                list.traverseBackward();
                break;

            case 9:
                cout << "  Enter value to search: ";
                cin >> value;
                list.search(value);
                break;

            case 10:
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