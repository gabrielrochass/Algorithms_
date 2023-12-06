#include <iostream>
using namespace std;

//sort the list
//quicksort

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}


void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int array_partition = partition(arr, low, high);

        quicksort(arr, low, array_partition - 1);
        quicksort(arr, array_partition +1, high);

    }
}

