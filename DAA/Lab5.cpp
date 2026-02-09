#include <iostream>
using namespace std;

int main() {
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[50];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter element to search: ";
    cin >> key;

    cout << "\nLINEAR SEARCH TRACING TABLE\n";
    cout << "Step\tIndex\ta[index]\tKey\tResult\n";
    cout << "---------------------------------------------\n";

    int pos = -1;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t"
             << i << "\t"
             << a[i] << "\t\t"
             << key << "\t";

        if (a[i] == key) {
            cout << "Found\n";
            pos = i;
            break;
        } else {
            cout << "Not Found\n";
        }
    }

    if (pos != -1)
        cout << "\nElement found at index " << pos
             << " (Position " << pos + 1 << ")\n";
    else
        cout << "\nElement not found in the array\n";

    return 0;
}
