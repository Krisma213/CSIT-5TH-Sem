#include <iostream>
using namespace std;

/* ---------- Divide and Conquer Min-Max ---------- */
void minMaxDC(int a[], int low, int high, int &minVal, int &maxVal, int &step) {
    int minL, maxL, minR, maxR;

    // Only one element
    if (low == high) {
        minVal = maxVal = a[low];
        cout << step++ << "\t[" << low << ".." << high << "]\t" << minVal << "\t" << maxVal << "\n";
        return;
    }

    // Two elements
    if (high == low + 1) {
        if (a[low] < a[high]) {
            minVal = a[low];
            maxVal = a[high];
        } else {
            minVal = a[high];
            maxVal = a[low];
        }
        cout << step++ << "\t[" << low << ".." << high << "]\t" << minVal << "\t" << maxVal << "\n";
        return;
    }

    // More than 2 elements
    int mid = (low + high) / 2;
    minMaxDC(a, low, mid, minL, maxL, step);
    minMaxDC(a, mid + 1, high, minR, maxR, step);

    minVal = (minL < minR) ? minL : minR;
    maxVal = (maxL > maxR) ? maxL : maxR;

    cout << step++ << "\t[" << low << ".." << high << "]\t" << minVal << "\t" << maxVal << "\n";
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

    cout << "\nDIVIDE AND CONQUER MIN-MAX TRACING\n";
    cout << "Step\tSubarray\tMin\tMax\n";
    cout << "-------------------------------------\n";

    int step = 1;
    int minVal, maxVal;
    minMaxDC(a, 0, n - 1, minVal, maxVal, step);

    cout << "\nFinal Result:\n";
    cout << "Minimum = " << minVal << "\n";
    cout << "Maximum = " << maxVal << "\n";

    return 0;
}
