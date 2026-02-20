#include <iostream>
using namespace std;

int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

int main() {
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    if (k < 0 || k > n) {
        cout << "Invalid input: k must be between 0 and n." << endl;
    } else {
        cout << "C(" << n << ", " << k << ") = " << binomialCoefficient(n, k) << endl;
    }

    return 0;
}