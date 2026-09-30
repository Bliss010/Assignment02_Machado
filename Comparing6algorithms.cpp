#include <iostream>
#include <chrono>
#include <random>
using namespace std;

void printArray(const int arr[], int n);

void bubbleSort(int arr[], int n, int &comparisons);
void insertionSort(int arr[], int n, int &comparisons);
void selectionSort(int arr[], int n, int &comparisons);

void quickSort(int arr[], int low, int high, int &comparisons);
int partitionArray(int arr[], int low, int high, int &comparisons);

void mergeSort(int arr[], int low, int high, int &comparisons);
void mergeArrays(int arr[], int low, int mid, int high, int &comparisons);

void heapSort(int arr[], int n, int &comparisons);
void siftDown(int arr[], int root, int size, int &comparisons);

//++++++++++++++++++++
int main()
{
    int A[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int n = sizeof(A) / sizeof(A[0]);

    int sortedA[] = {5, 7, 14, 19, 23, 32, 34, 62};
    int reversedA[] = {62, 34, 32, 23, 19, 14, 7, 5};

    cout << "Comparing it now" << endl;

    int comparisons;
//++++++++++++++++++++
    // Bubble
    comparisons = 0;
    bubbleSort(A, n, comparisons);
    cout << "Bubble Sort - A: " << comparisons;

    comparisons = 0;
    bubbleSort(sortedA, n, comparisons);
    cout << "  Sorted: " << comparisons;

    comparisons = 0;
    bubbleSort(reversedA, n, comparisons);
    cout << "  Reversed: " << comparisons << endl;


    // Insertion
    int B1[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int B2[] = {5, 7, 14, 19, 23, 32, 34, 62};
    int B3[] = {62, 34, 32, 23, 19, 14, 7, 5};

    comparisons = 0;
    insertionSort(B1, n, comparisons);
    cout << "Insertion Sort - A: " << comparisons;

    comparisons = 0;
    insertionSort(B2, n, comparisons);
    cout << "  Sorted: " << comparisons;

    comparisons = 0;
    insertionSort(B3, n, comparisons);
    cout << "  Reversed: " << comparisons << endl;


    // Selection
    int C1[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int C2[] = {5, 7, 14, 19, 23, 32, 34, 62};
    int C3[] = {62, 34, 32, 23, 19, 14, 7, 5};

    comparisons = 0;
    selectionSort(C1, n, comparisons);
    cout << "Selection Sort - A: " << comparisons;

    comparisons = 0;
    selectionSort(C2, n, comparisons);
    cout << "  Sorted: " << comparisons;

    comparisons = 0;
    selectionSort(C3, n, comparisons);
    cout << "  Reversed: " << comparisons << endl;


    // Quick
    int D1[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int D2[] = {5, 7, 14, 19, 23, 32, 34, 62};
    int D3[] = {62, 34, 32, 23, 19, 14, 7, 5};

    comparisons = 0;
    quickSort(D1, 0, n - 1, comparisons);
    cout << "Quick Sort - A: " << comparisons;

    comparisons = 0;
    quickSort(D2, 0, n - 1, comparisons);
    cout << "  Sorted: " << comparisons;

    comparisons = 0;
    quickSort(D3, 0, n - 1, comparisons);
    cout << "  Reversed: " << comparisons << endl;


    // Merge
    int E1[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int E2[] = {5, 7, 14, 19, 23, 32, 34, 62};
    int E3[] = {62, 34, 32, 23, 19, 14, 7, 5};

    comparisons = 0;
    mergeSort(E1, 0, n - 1, comparisons);
    cout << "Merge Sort - A: " << comparisons;

    comparisons = 0;
    mergeSort(E2, 0, n - 1, comparisons);
    cout << "  Sorted: " << comparisons;

    comparisons = 0;
    mergeSort(E3, 0, n - 1, comparisons);
    cout << "  Reversed: " << comparisons << endl;


    // heap
    int F1[] = {34, 7, 23, 32, 5, 62, 14, 19};
    int F2[] = {5, 7, 14, 19, 23, 32, 34, 62};
    int F3[] = {62, 34, 32, 23, 19, 14, 7, 5};

    comparisons = 0;
    heapSort(F1, n, comparisons);
    cout << "Heap Sort - A: " << comparisons;

    comparisons = 0;
    heapSort(F2, n, comparisons);
    cout << "  Sorted: " << comparisons;

    comparisons = 0;
    heapSort(F3, n, comparisons);
    cout << "  Reversed: " << comparisons << endl;

//the timing tests

    cout << endl;
    cout << "========== TIMING TEST ==========" << endl;

    int sizes[] = {1000, 5000, 10000};

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 100000);

    for (int s = 0; s < 3; s++)
    {
        int size = sizes[s];

        int *baseArray = new int[size];

        for (int i = 0; i < size; i++)
        {
            baseArray[i] = distribution(generator);
        }

        cout << endl;
        cout << "Array size: " << size << endl;


        // Thos is bubble
        int *arr1 = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr1[i] = baseArray[i];
        }

        comparisons = 0;

        auto start = chrono::high_resolution_clock::now();

        bubbleSort(arr1, size, comparisons);

        auto finish = chrono::high_resolution_clock::now();

        auto timeBubble =
            chrono::duration_cast<chrono::microseconds>(finish - start).count();

        cout << "Bubble Sort: " << timeBubble << " microseconds" << endl;
        cout << "First 10: ";
        printArray(arr1, 10);

        delete[] arr1;


        // This is insertion
        int *arr2 = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr2[i] = baseArray[i];
        }

        comparisons = 0;

        start = chrono::high_resolution_clock::now();

        insertionSort(arr2, size, comparisons);

        finish = chrono::high_resolution_clock::now();

        auto timeInsertion =
            chrono::duration_cast<chrono::microseconds>(finish - start).count();

        cout << "Insertion Sort: " << timeInsertion << " microseconds" << endl;
        cout << "First 10: ";
        printArray(arr2, 10);

        delete[] arr2;


        // this is selection
        int *arr3 = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr3[i] = baseArray[i];
        }

        comparisons = 0;

        start = chrono::high_resolution_clock::now();

        selectionSort(arr3, size, comparisons);

        finish = chrono::high_resolution_clock::now();

        auto timeSelection =
            chrono::duration_cast<chrono::microseconds>(finish - start).count();

        cout << "Selection Sort: " << timeSelection << " microseconds" << endl;
        cout << "First 10: ";
        printArray(arr3, 10);

        delete[] arr3;


        // This is quick
        int *arr4 = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr4[i] = baseArray[i];
        }

        comparisons = 0;

        start = chrono::high_resolution_clock::now();

        quickSort(arr4, 0, size - 1, comparisons);

        finish = chrono::high_resolution_clock::now();

        auto timeQuick =
            chrono::duration_cast<chrono::microseconds>(finish - start).count();

        cout << "Quick Sort: " << timeQuick << " microseconds" << endl;
        cout << "First 10: ";
        printArray(arr4, 10);

        delete[] arr4;


        // This is merge
        int *arr5 = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr5[i] = baseArray[i];
        }

        comparisons = 0;

        start = chrono::high_resolution_clock::now();

        mergeSort(arr5, 0, size - 1, comparisons);

        finish = chrono::high_resolution_clock::now();

        auto timeMerge =
            chrono::duration_cast<chrono::microseconds>(finish - start).count();

        cout << "Merge Sort: " << timeMerge << " microseconds" << endl;
        cout << "First 10: ";
        printArray(arr5, 10);

        delete[] arr5;


        // This is Heap 
        int *arr6 = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr6[i] = baseArray[i];
        }

        comparisons = 0;

        start = chrono::high_resolution_clock::now();

        heapSort(arr6, size, comparisons);

        finish = chrono::high_resolution_clock::now();

        auto timeHeap =
            chrono::duration_cast<chrono::microseconds>(finish - start).count();

        cout << "Heap Sort: " << timeHeap << " microseconds" << endl;
        cout << "First 10: ";
        printArray(arr6, 10);

        delete[] arr6;

        delete[] baseArray;
    }

    return 0;
}


//print it, the arry

void printArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}


//++++++++++++++++++++++++
// Bubble Sort
//+++++++++++++++++++++++

void bubbleSort(int arr[], int n, int &comparisons)
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

                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}


//+++++++++++++++++++++++++
// Insertion Sort
//++++++++++++++++++++

void insertionSort(int arr[], int n, int &comparisons)
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

                j--;
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = key;
    }
}


//+++++++++++++++++++++++++
// Selection Sort
//++++++++++++++++++++++++

void selectionSort(int arr[], int n, int &comparisons)
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

        int temp = arr[i];

        arr[i] = arr[minIndex];

        arr[minIndex] = temp;
    }
}


//+++++++++++++++++++++++++
// Quick Sort
//++++++++++++++++++++++

void quickSort(int arr[], int low, int high, int &comparisons)
{
    if (low < high)
    {
        int pivotIndex = partitionArray(arr, low, high, comparisons);

        quickSort(arr, low, pivotIndex - 1, comparisons);

        quickSort(arr, pivotIndex + 1, high, comparisons);
    }
}


int partitionArray(int arr[], int low, int high, int &comparisons)
{
    int pivot = arr[high];

    int i = low;

    for (int j = low; j < high; j++)
    {
        comparisons++;

        if (arr[j] <= pivot)
        {
            int temp = arr[i];

            arr[i] = arr[j];

            arr[j] = temp;

            i++;
        }
    }

    int temp = arr[i];

    arr[i] = arr[high];

    arr[high] = temp;

    return i;
}


//++++++++++++++++++++++++++
// Merge Sort
//+++++++++++++++++++++++

void mergeSort(int arr[], int low, int high, int &comparisons)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid, comparisons);

        mergeSort(arr, mid + 1, high, comparisons);

        mergeArrays(arr, low, mid, high, comparisons);
    }
}


void mergeArrays(int arr[], int low, int mid, int high, int &comparisons)
{
    int size1 = mid - low + 1;

    int size2 = high - mid;

    int *left = new int[size1];

    int *right = new int[size2];

    for (int i = 0; i < size1; i++)
    {
        left[i] = arr[low + i];
    }

    for (int j = 0; j < size2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < size1 && j < size2)
    {
        comparisons++;

        if (left[i] <= right[j])
        {
            arr[k] = left[i];

            i++;
        }
        else
        {
            arr[k] = right[j];

            j++;
        }

        k++;
    }

    while (i < size1)
    {
        arr[k] = left[i];

        i++;
        k++;
    }

    while (j < size2)
    {
        arr[k] = right[j];

        j++;
        k++;
    }

    delete[] left;

    delete[] right;
}


//+++++++++++++++++++++++++++
// Heap Sort
//+++++++++++++++

void heapSort(int arr[], int n, int &comparisons)
{
    for (int root = n / 2 - 1; root >= 0; root--)
    {
        siftDown(arr, root, n, comparisons);
    }

    for (int end = n - 1; end >= 1; end--)
    {
        int temp = arr[0];

        arr[0] = arr[end];

        arr[end] = temp;

        siftDown(arr, 0, end, comparisons);
    }
}


void siftDown(int arr[], int root, int size, int &comparisons)
{
    while (2 * root + 1 < size)
    {
        int child = 2 * root + 1;

        if (child + 1 < size)
        {
            comparisons++;

            if (arr[child + 1] > arr[child])
            {
                child = child + 1;
            }
        }

        comparisons++;

        if (arr[root] >= arr[child])
        {
            return;
        }

        int temp = arr[root];

        arr[root] = arr[child];

        arr[child] = temp;

        root = child;
    }
}