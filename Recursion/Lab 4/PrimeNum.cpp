#include <iostream>
using namespace std;

bool isPrime(int n, int i = 2) {
    if (n <= 1)
        return false;
    if (i == n)
        return true;
    if (n % i == 0)
        return false;

    return isPrime(n, i + 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPrime(n))
        cout << n << " is a prime number.";
    else
        cout << n << " is not a prime number.";

    return 0;
}