#include <iostream>
using namespace std;

int comparisons = 0;
int finalMergeComparisons = 0;
int originalSize = 8;
//++++++++++++++++
void printArray(const int arr[], int n);
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
//++++++++++++++++++
int main()
{
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(A) / sizeof(A[0]);

    comparisons = 0;
    finalMergeComparisons = 0;

    cout << "Original: ";
    printArray(A, n);

    mergeSort(A, 0, n - 1);

    cout << "Sorted: ";
    printArray(A, n);

    cout << "Comparisons: " << comparisons;
    cout << " (final merge: " << finalMergeComparisons << ")" << endl;

//+++++++++++++++++

    int B[] = {5, 7, 14, 19, 23, 32, 34, 62};

    comparisons = 0;
    finalMergeComparisons = 0;

    cout << endl;
    cout << "Already sorted: ";
    printArray(B, n);

    mergeSort(B, 0, n - 1);

    cout << "Sorted: ";
    printArray(B, n);

    cout << "Comparisons: " << comparisons;
    cout << " (final merge: " << finalMergeComparisons << ")" << endl;

    //++++++++++++

    int C[] = {62, 34, 32, 23, 19, 14, 7, 5};

    comparisons = 0;
    finalMergeComparisons = 0;

    cout << endl;
    cout << "Reversed: ";
    printArray(C, n);

    mergeSort(C, 0, n - 1);

    cout << "Sorted: ";
    printArray(C, n);

    cout << "Comparisons: " << comparisons;
    cout << " (final merge: " << finalMergeComparisons << ")" << endl;

    return 0;
}
//++++++++++++
void printArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
//++++++++++++++++++
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        cout << "split: ";
        printArray(arr + low, high - low + 1);

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);

        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}
//+++++++++++++++++++++
void merge(int arr[], int low, int mid, int high)
{
    int size = high - low + 1;
    int temp[8];

    int i = low;
    int j = mid + 1;
    int k = 0;

    int mergeComparisons = 0;

    while (i <= mid && j <= high)
    {
        comparisons++;
        mergeComparisons++;

        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int x = 0; x < size; x++)
    {
        arr[low + x] = temp[x];
    }

    if (low == 0 && high == originalSize - 1)
    {
        finalMergeComparisons = mergeComparisons;
    }

    cout << "merged: ";
    printArray(arr + low, high - low + 1);
}