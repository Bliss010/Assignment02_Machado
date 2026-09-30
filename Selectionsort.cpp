#include <iostream>
using namespace std;

void printArray(const int arr[], int n);
void selectionSort(int arr[], int n, int &comparisons, int &swaps);
//++++++++++++
int main()
{
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(A) / sizeof(A[0]);

    int comparisons = 0;
    int swaps = 0;

    cout << "Original: ";
    printArray(A, n);

    selectionSort(A, n, comparisons, swaps);

    cout << "Sorted: ";
    printArray(A, n);

    cout << "Comparisons: " << comparisons;
    cout << " Swaps: " << swaps << endl;

    return 0;
}
//+++++++++
void printArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
//+++++++++++
void selectionSort(int arr[], int n, int &comparisons, int &swaps)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;

            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = arr[i];

            arr[i] = arr[minIndex];

            arr[minIndex] = temp;

            swaps++;
        }

        cout << "Pass " << i + 1 << ": min = "
             << arr[i] << " at index " << minIndex << " -> ";

        printArray(arr, n);
    }
}