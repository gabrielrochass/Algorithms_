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

void prefixSum(int arr[], int size, long long int prefixArray[]) {

    prefixArray[0] = arr[0];

    for (int i = 1; i < size; i++)
    {
        prefixArray[i] = prefixArray[i-1] + arr[i];
    }

}


int main() {

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int number_of_items;
    int queue;

    cin >> number_of_items >> queue;
    number_of_items++;
    int arr[number_of_items];
    arr[0] = 0;
    for (int i = 1; i < number_of_items; i++)
    {
        cin >> arr[i];
    }

     mergeSort(arr, 0, number_of_items-1, number_of_items);

    long long int prefixArray[number_of_items];
    prefixSum(arr, number_of_items, prefixArray);


    int lasts, forFree;

    for (int k = 0; k < queue; k++)
    {
        cin >> lasts >> forFree;

        long long int result = prefixArray[number_of_items - lasts + forFree -1] - prefixArray[number_of_items- lasts - 1];
        cout << result << endl;
    }

    return 0;
    }