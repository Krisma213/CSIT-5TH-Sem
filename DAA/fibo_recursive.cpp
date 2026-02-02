#include <iostream>
using namespace std;

int fib(int n) {
    cout << "fib(" << n << ") called" << endl;

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    cout << "\nTracing (Recursive Method):\n";
    cout << "---------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << "Fibonacci(" << i << ") = " << fib(i) << endl;
        cout << "-------------------\n";
    }

    return 0;
}
