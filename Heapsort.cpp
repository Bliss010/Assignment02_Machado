#include <iostream>
using namespace std;

void printArray(const int arr[], int n);
void siftDown(int arr[], int root, int size, int &swaps);
void heapSort(int arr[], int n, int &swaps);
//++++++++++++++++++++
int main()
{
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(A) / sizeof(A[0]);

    int swaps = 0;

    cout << "Original: ";
    printArray(A, n);

    heapSort(A, n, swaps);

    cout << "Sorted: ";
    printArray(A, n);

    cout << "Swaps in siftDown: " << swaps << endl;

    return 0;
}
//+++++++++++++++++++++
void printArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
//++++++++++++++++++++++++++
void siftDown(int arr[], int root, int size, int &swaps)
{
    while (2 * root + 1 < size)
    {
        int child = 2 * root + 1;

        if (child + 1 < size && arr[child + 1] > arr[child])
        {
            child = child + 1;
        }

        if (arr[root] >= arr[child])
        {
            return;
        }

        int temp = arr[root];

        arr[root] = arr[child];

        arr[child] = temp;

        swaps++;

        root = child;
    }
}
//+++++++++++++++++++
void heapSort(int arr[], int n, int &swaps)
{
    for (int root = n / 2 - 1; root >= 0; root--)
    {
        siftDown(arr, root, n, swaps);
    }

    cout << "Heap: ";
    printArray(arr, n);

    for (int end = n - 1; end >= 1; end--)
    {
        int temp = arr[0];

        arr[0] = arr[end];

        arr[end] = temp;

        siftDown(arr, 0, end, swaps);

        cout << "end = " << end << ": heap: ";
        printArray(arr, end);

        cout << "sorted: ";
        printArray(arr + end, n - end);
    }
}