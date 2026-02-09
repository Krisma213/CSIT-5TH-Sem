#include <iostream>
#include <iomanip>
using namespace std;

/* Utility function */
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

/* ---------- MERGE SORT ---------- */
void merge(int a[], int l, int m, int r, int n) {
    int i = l, j = m + 1, k = 0;
    int temp[50];

    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];

    cout << "Merge [" << l << ".." << r << "] : ";
    printArray(a, n);
}

void mergeSort(int a[], int l, int r, int n) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m, n);
        mergeSort(a, m + 1, r, n);
        merge(a, l, m, r, n);
    }
}

/* ---------- QUICK SORT ---------- */
int partition(int a[], int low, int high, int n) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && a[i] <= pivot) i++;
        while (a[j] > pivot) j--;
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[low], a[j]);

    cout << "Pivot " << pivot << " placed : ";
    printArray(a, n);

    return j;
}

void quickSort(int a[], int low, int high, int n) {
    if (low < high) {
        int p = partition(a, low, high, n);
        quickSort(a, low, p - 1, n);
        quickSort(a, p + 1, high, n);
    }
}

/* ---------- MAIN ---------- */
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[50], b[50];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];   // copy for quick sort
    }

    cout << "\nMERGE SORT TRACING\n";
    cout << "Initial Array: ";
    printArray(a, n);
    mergeSort(a, 0, n - 1, n);

    cout << "\nQUICK SORT TRACING\n";
    cout << "Initial Array: ";
    printArray(b, n);
    quickSort(b, 0, n - 1, n);

    return 0;
}
