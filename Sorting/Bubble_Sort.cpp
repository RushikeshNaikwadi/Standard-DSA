#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        bool swapped = 0;
        for (int j = 1; j < n; j++) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                swapped = 1;
            }
        }
        if (not swapped) {
            break;
        }
    }
}

int main () {
    int arr[] = {7, 9, 4, 6, 8, 1, 3, 2, 5};
    int n = sizeof(arr) / sizeof(int);

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) 
        cout << arr[i] << ' ';
    
    return 0;   
}