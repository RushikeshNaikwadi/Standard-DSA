#include <bits/stdc++.h>
using namespace std;

int partition (int *arr, int l, int r) {
    int leftPart = l - 1;
    for (int i = l; i <= r; i++) {
        if (arr[i] <= arr[r]) {
            leftPart++;
            swap(arr[leftPart], arr[i]);
        }
    }
    return leftPart;
}

void quickSort(int *arr, int l, int r) {
    if (l < r) {
        int partitionIdx = partition(arr, l, r);


        quickSort(arr, l, partitionIdx - 1);
        quickSort(arr, partitionIdx + 1, r);
    }
}

int main () {
    int arr[] = {7, 9, 4, 6, 8, 1, 3, 2, 5};
    int n = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) 
        cout << arr[i] << ' ';  
    
    return 0;   
}