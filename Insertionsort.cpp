#include <iostream>
using namespace std;

void printArray(const int arr[], int n);
void insertionSort(int arr[], int n, int &comparisons, int &shifts);
//++++++++++++++++++++
int main()
{
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(A) / sizeof(A[0]);

    int comparisons = 0;
    int shifts = 0;

    cout << "Original: ";
    printArray(A, n);

    insertionSort(A, n, comparisons, shifts);

    cout << "Sorted: ";
    printArray(A, n);

    cout << "Comparisons: " << comparisons;
    cout << " Shifts: " << shifts << endl;

//+++++++++++++++++
    int B[] = {5, 7, 14, 19, 23, 32, 34, 62};

    comparisons = 0;
    shifts = 0;

    cout << endl;
    cout << "Already sorted: ";
    printArray(B, n);

    insertionSort(B, n, comparisons, shifts);

    cout << "Sorted: ";
    printArray(B, n);

    cout << "Comparisons: " << comparisons;
    cout << " Shifts: " << shifts << endl;

//++++++++++++++++++++++
    int C[] = {62, 34, 32, 23, 19, 14, 7, 5};

    comparisons = 0;
    shifts = 0;

    cout << endl;
    cout << "Reversed: ";
    printArray(C, n);

    insertionSort(C, n, comparisons, shifts);

    cout << "Sorted: ";
    printArray(C, n);

    cout << "Comparisons: " << comparisons;
    cout << " Shifts: " << shifts << endl;

    return 0;
}
//+++++++++++++++
void printArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
//++++++++++++++++
void insertionSort(int arr[], int n, int &comparisons, int &shifts)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++;

            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];

                shifts++;

                j--;
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = key;

        cout << "i = " << i << ", key = " << key << ": ";
        printArray(arr, n);
    }
}
