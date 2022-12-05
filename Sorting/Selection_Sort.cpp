#include <bits/stdc++.h>
using namespace std;

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main () {
    int arr[] = {7, 9, 4, 6, 8, 1, 3, 2, 5};
    int n = sizeof(arr) / sizeof(int);

    selectionSort(arr, n);

    for (int i = 0; i < n; i++) 
        cout << arr[i] << ' ';  
    
    return 0;   
}