#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    int temp[end - start + 1];
    int i = start, j = mid + 1, k = 0;

    // Merge two halves
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];

    // Copy sorted data back to original array
    for (int i = 0; i < k; i++)
        arr[i+start] = temp[i];
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int arr[] = {10, 5, 6, 0, 9, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}
