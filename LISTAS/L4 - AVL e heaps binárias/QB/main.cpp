#include <iostream>
#include <vector>

using namespace std;

struct MinHeap {
    vector<long long> heap;

    void heapifyUp(int index) {
        if (index == 0)
            return;

        int parentIndex = (index - 1) / 2;
        if (heap[parentIndex] > heap[index]) {
            swap(heap[parentIndex], heap[index]);
            heapifyUp(parentIndex);
        }
    }

    void insert(long long value) {
        heap.push_back(value);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
            smallest = leftChild;

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }
};

int main() {
    while (true) {
        int n;
        cin >> n;

        if (n == 0)
            break;

        MinHeap minHeap;

        for (int i = 0; i < n; ++i) {
            long long num;
            cin >> num;
            minHeap.insert(num);
        }

        long long totalCost = 0;

        while (minHeap.heap.size() > 1) {
            long long a = minHeap.heap[0];
            minHeap.heap[0] = minHeap.heap.back();
            minHeap.heap.pop_back();
            minHeap.heapifyDown(0);

            long long b = minHeap.heap[0];
            minHeap.heap[0] = minHeap.heap.back();
            minHeap.heap.pop_back();
            minHeap.heapifyDown(0);

            long long sum = a + b;
            totalCost += sum;

            minHeap.insert(sum);
        }

        cout << totalCost << endl;
    }

    return 0;
}

