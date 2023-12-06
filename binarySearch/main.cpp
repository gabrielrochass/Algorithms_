//binarySearch

#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int number_to_search_for) {
    while (low <= high) {
        int mid = low + (high - low)/2;

        if (number_to_search_for == arr[mid]) {
            return mid;
        }

        if (number_to_search_for > arr[mid]) {
            low = mid + 1;
        }

        if (number_to_search_for < arr[mid]) {
            high = mid - 1;
        }
    }
    return -1;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

}

int main() {
    int size;
    cout << "size:" << endl;
    cin >> size;

    int arr[size];
    cout << "array:" << endl;

    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    int key;
    cout << "key:" << endl;
    cin >> key;

    int result = binarySearch(arr, 0, size-1, key);
    if (result == -1)
    {
        cout << "element is not in the array" << endl;;
    }
    else {
        cout << "the index is " << result << endl;
    }





}
