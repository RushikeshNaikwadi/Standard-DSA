#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int l, int mid, int r) {
    int aux[r - l + 1] = {0};

    int auxIdx = 0, firstHalfIdx = l, secondHalfIdx = mid + 1;
    while (firstHalfIdx <= mid and secondHalfIdx <= r) {
        aux[auxIdx++] = (arr[firstHalfIdx] < arr[secondHalfIdx] ? arr[firstHalfIdx++] : arr[secondHalfIdx++]);
    }

    while (firstHalfIdx <= mid) {
        aux[auxIdx++] = arr[firstHalfIdx++];
    }

    while (secondHalfIdx <= r) {
        aux[auxIdx++] = arr[secondHalfIdx++];
    }

    for (int inArr = l, inAux = 0; inArr <= r; inArr++, inAux++) {
        arr[inArr] = aux[inAux];
    }    
}

void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main () {
    int arr[] = {7, 9, 4, 6, 1, 3, 2, 5, 8};
    int n = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) 
        cout << arr[i] << ' ';  
    
    return 0;   
}