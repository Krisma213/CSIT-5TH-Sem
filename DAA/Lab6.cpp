#include <iostream>
#include <iomanip>
using namespace std;

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// -------- BUBBLE SORT --------
void bubbleSort(int a[], int n) {
    cout << "\nBUBBLE SORT TRACING\n";
    cout << "Pass\tArray\n";

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
        cout << i + 1 << "\t";
        printArray(a, n);
    }
}

// -------- INSERTION SORT --------
void insertionSort(int a[], int n) {
    cout << "\nINSERTION SORT TRACING\n";
    cout << "Pass\tArray\n";

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        cout << i << "\t";
        printArray(a, n);
    }
}

// -------- SELECTION SORT --------
void selectionSort(int a[], int n) {
    cout << "\nSELECTION SORT TRACING\n";
    cout << "Pass\tArray\n";

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);

        cout << i + 1 << "\t";
        printArray(a, n);
    }
}

// -------- MAIN --------
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n], b[n], c[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = c[i] = a[i];   // copies for other sorts
    }

    bubbleSort(a, n);
    insertionSort(b, n);
    selectionSort(c, n);

    return 0;
}
