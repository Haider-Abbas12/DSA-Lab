#include "Polynomial.h"
#include "Polynomial.cpp"
int main() {

    string filename;
    cout << "Enter the name of the polynomial file => ";
    cin >> filename;

    Polynomial poly;
    try {
        poly.readFromFile(filename);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    cout << filename << " ";
    poly.display();

    int choice = 0;

    while (choice != 4) {
        cout << "\n1. ADD polynomial\n";
        cout << "2. MULTIPLY polynomial\n";
        cout << "3. EVALUATE polynomial\n";
        cout << "4. QUIT\n";
        cout << "\nEnter choice # => ";
        cin >> choice;
        cout << endl;

        // ADD
        if (choice == 1) {
            string file2;
            cout << "Enter the file containing the polynomial to add\n=> ";
            cin >> file2;

            Polynomial poly2;
            try {
                poly2.readFromFile(file2);
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
                continue;
            }

            cout << file2 << " ";
            poly2.display();

            Polynomial sum = poly + poly2;
            cout << "Sum: ";
            sum.display();
        }

        // MULTIPLY
        else if (choice == 2) {
            string file2;
            cout << "Enter the file containing the polynomial to multiply\n=> ";
            cin >> file2;

            Polynomial poly2;
            try {
                poly2.readFromFile(file2);
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
                continue;
            }

            cout << file2 << " ";
            poly2.display();

            Polynomial product = poly * poly2;
            cout << "Product: ";
            product.display();
        }

        // EVALUATE
        else if (choice == 3) {
            double x;
            cout << "Enter the value of x => ";
            cin >> x;

            double result = poly.evaluate(x);
            cout << "P(" << x << ") = " << result << endl;
        }

        // QUIT
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
        }

        else {
            cout << "Invalid choice. Please enter 1-4." << endl;
        }
    }

    return 0;
}