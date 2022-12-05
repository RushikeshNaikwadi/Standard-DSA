#include <bits/stdc++.h>
using namespace std;

void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            } else {
                break;
            }
        }
    }
}

int main () {
    int arr[] = {7, 9, 4, 6, 8, 1, 3, 2, 5};
    int n = sizeof(arr) / sizeof(int);

    insertionSort(arr, n);

    for (int i = 0; i < n; i++) 
        cout << arr[i] << ' ';  
    
    return 0;   
}