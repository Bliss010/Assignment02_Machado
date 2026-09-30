#include <iostream>
using namespace std;

void printArray(const int arr[], int n);
int partition(int arr[], int low, int high, int &comparisons, int depth);
void quickSort(int arr[], int low, int high, int &comparisons, int depth);
//++++++++++++++
int main()
{
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(A) / sizeof(A[0]);

    int comparisons = 0;

    cout << "Original: ";
    printArray(A, n);

    quickSort(A, 0, n - 1, comparisons, 0);

    cout << "Sorted: ";
    printArray(A, n);

    cout << "Comparisons: " << comparisons << endl;
//++++++++++++++

    int B[] = {5, 7, 14, 19, 23, 32, 34, 62};

    comparisons = 0;

    cout << endl;
    cout << "Already sorted: ";
    printArray(B, n);

    quickSort(B, 0, n - 1, comparisons, 0);

    cout << "Sorted: ";
    printArray(B, n);

    cout << "Comparisons: " << comparisons << endl;

    return 0;
}
//+++++++++++
void printArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
//+++++++++++++++
int partition(int arr[], int low, int high, int &comparisons, int depth)
{
    int pivot = arr[high];

    int i = low - 1;

    cout << "pivot = " << pivot << ": ";
    printArray(arr + low, high - low + 1);

    for (int j = low; j < high; j++)
    {
        if (depth == 0)
        {
            cout << "i = " << i << ", j = " << j << endl;
        }

        comparisons++;

        if (arr[j] <= pivot)
        {
            i++;

            int temp = arr[i];

            arr[i] = arr[j];

            arr[j] = temp;

            if (depth == 0)
            {
                cout << "After swap: ";
                printArray(arr, high + 1);
            }
        }
    }

    int temp = arr[i + 1];

    arr[i + 1] = arr[high];

    arr[high] = temp;

    if (depth == 0)
    {
        cout << "Pivot final position: " << i + 1 << endl;
        printArray(arr, high + 1);
    }

    return i + 1;
}
//+++++++++++++++
void quickSort(int arr[], int low, int high, int &comparisons, int depth)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high, comparisons, depth);

        for (int k = 0; k < depth; k++)
        {
            cout << " ";
        }

        cout << "pivot = " << arr[pivotIndex] << ": ";
        printArray(arr + low, high - low + 1);

        quickSort(arr, low, pivotIndex - 1, comparisons, depth + 1);

        quickSort(arr, pivotIndex + 1, high, comparisons, depth + 1);
    }
}