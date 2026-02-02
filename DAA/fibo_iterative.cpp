#include <iostream>
using namespace std;

int main() {
    int n;
    int a = 0, b = 1, c;

    cout << "Enter number of terms: ";
    cin >> n;

    cout << "\nTracing (Iterative Method):\n";
    cout << "Step\tFibonacci\n";
    cout << "-----------------\n";

    if (n >= 1)
        cout << "1\t" << a << endl;
    if (n >= 2)
        cout << "2\t" << b << endl;

    for (int i = 3; i <= n; i++) {
        c = a + b;
        cout << i << "\t" << c << endl;
        a = b;
        b = c;
    }

    return 0;
}
