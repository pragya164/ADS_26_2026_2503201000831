#include <iostream>
#include <vector>
#include <climits>   // Required for INT_MAX

using namespace std;
void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);

    // Copy elements into left subarray
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }

    // Copy elements into right subarray
    for (int j = 0; j < n2; j++) {
        R[j] = A[q + j + 1];
    }

    // Sentinel values
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0;
    int j = 0;

    // Merge the two sorted subarrays
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

int main() {
    int A[] = {1, 2, 3, 6, 18, 20, 50, 62};
    int n = sizeof(A) / sizeof(A[0]);

    // Example: merge A[p...q] and A[q+1...r]
    int p = 0;
    int q = 3;
    int r = 7;

    merge(A, p, q, r);

    cout << "Merged array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}