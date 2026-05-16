#include <iostream>
#include <iomanip>
using namespace std;

/* Print array */
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

/* ---------- HEAPIFY ---------- */
void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

/* ---------- BUILD HEAP ---------- */
void buildHeap(int a[], int n) {
    cout << "\nBUILD MAX HEAP (Tracing)\n";
    cout << "Step\tArray\n";

    int step = 1;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
        cout << step++ << "\t";
        printArray(a, n);
    }
}

/* ---------- HEAP SORT ---------- */
void heapSort(int a[], int n) {
    cout << "\nHEAP SORT (Tracing)\n";
    cout << "Step\tArray\n";

    int step = 1;
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);       // move max to end
        heapify(a, i, 0);       // heapify reduced heap

        cout << step++ << "\t";
        printArray(a, n);
    }
}

/* ---------- MAIN ---------- */
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[50];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\nInitial Array: ";
    printArray(a, n);

    buildHeap(a, n);
    heapSort(a, n);

    cout << "\nFinal Sorted Array: ";
    printArray(a, n);

    return 0;
}
