#include <iostream>
using namespace std;
#define endl  '\n'

void merge(int arr[], int low, int mid, int high, int size) {
    int i = low; //indice incial do left array
    int j = mid +1; //indice inicial do right array
    int k = low; // indice inicial de temp

    int temp[size];

    while (i <= mid and j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid) {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= high) {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (int y = low; y <= high ; ++y) {
        arr[y] = temp[y];
    }
}


void mergeSort(int arr[], int low, int high, int size) {
    if (low < high) {
        int mid = low + (high - low) /2;

        mergeSort(arr, low, mid, size); //left subarray
        mergeSort(arr, mid + 1, high, size); //right subarray
        merge(arr,low, mid, high, size);
    }
}
