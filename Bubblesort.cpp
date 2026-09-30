#include <iostream>
using namespace std;

void printArray(const int arr[], int n);
void bubbleSort(int arr[], int n, int &comparisons, int &swaps);
//+++++++++
int main()
{
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(A) / sizeof(A[0]);

    int comparisons = 0;
    int swaps = 0;

    cout << "Original: ";
    printArray(A, n);

    bubbleSort(A, n, comparisons, swaps);

    cout << "Sorted: ";
    printArray(A, n);

    cout << "Comparisons: " << comparisons;
    cout << " Swaps: " << swaps << endl;

    return 0;
}
//++++++++++
void printArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
//++++++++
void bubbleSort(int arr[], int n, int &comparisons, int &swaps)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - 1 - i; j++)
        {
            comparisons++;

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps++;
                swapped = true;
            }
        }
//++++++++++++
        cout << "Pass " << i + 1 << ": ";
        printArray(arr, n);

        if (swapped == false)
        {
            break;
        }
    }
}