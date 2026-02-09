#include <iostream>
using namespace std;

/* ---------- ITERATIVE BINARY SEARCH ---------- */
int binarySearchIterative(int a[], int n, int key) {
    int low = 0, high = n - 1, mid;
    int step = 1;

    cout << "\nITERATIVE BINARY SEARCH TRACING\n";
    cout << "Step\tLow\tHigh\tMid\ta[mid]\tResult\n";
    cout << "---------------------------------------------\n";

    while (low <= high) {
        mid = (low + high) / 2;

        cout << step << "\t"
             << low << "\t"
             << high << "\t"
             << mid << "\t"
             << a[mid] << "\t";

        if (a[mid] == key) {
            cout << "Found\n";
            return mid;
        } else if (a[mid] < key) {
            cout << "Right Half\n";
            low = mid + 1;
        } else {
            cout << "Left Half\n";
            high = mid - 1;
        }
        step++;
    }

    return -1;
}

/* ---------- RECURSIVE BINARY SEARCH ---------- */
int stepRec = 1;

int binarySearchRecursive(int a[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    cout << stepRec << "\t"
         << low << "\t"
         << high << "\t"
         << mid << "\t"
         << a[mid] << "\t";

    if (a[mid] == key) {
        cout << "Found\n";
        return mid;
    } else if (a[mid] < key) {
        cout << "Right Half\n";
        stepRec++;
        return binarySearchRecursive(a, mid + 1, high, key);
    } else {
        cout << "Left Half\n";
        stepRec++;
        return binarySearchRecursive(a, low, mid - 1, key);
    }
}

/* ---------- MAIN ---------- */
int main() {
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[50];
    cout << "Enter elements in sorted order:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter element to search: ";
    cin >> key;

    /* Iterative */
    int pos1 = binarySearchIterative(a, n, key);
    if (pos1 != -1)
        cout << "Element found at index " << pos1
             << " (Position " << pos1 + 1 << ")\n";
    else
        cout << "Element not found (Iterative)\n";

    /* Recursive */
    cout << "\nRECURSIVE BINARY SEARCH TRACING\n";
    cout << "Step\tLow\tHigh\tMid\ta[mid]\tResult\n";
    cout << "---------------------------------------------\n";

    stepRec = 1;
    int pos2 = binarySearchRecursive(a, 0, n - 1, key);

    if (pos2 != -1)
        cout << "Element found at index " << pos2
             << " (Position " << pos2 + 1 << ")\n";
    else
        cout << "Element not found (Recursive)\n";

    return 0;
}
