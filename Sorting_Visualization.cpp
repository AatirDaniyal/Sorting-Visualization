#include <iostream>
#include <vector>
using namespace std;

// Function to print the current state of the array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << "#"; // Visual representation of array values
        }
        cout << " (" << arr[i] << ")" << endl;
    }
    cout << "------------------" << endl;
}

// Bubble Sort Algorithm with Visualization
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);

                // Visualize after each swap
                printArray(arr);
                
            }
        }
    }
}

// Insertion Sort Algorithm with Visualization
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            printArray(arr);
            
        }
        arr[j + 1] = key;
    }
}

// Selection Sort Algorithm with Visualization
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);

        // Visualize after each selection
        printArray(arr);
        
    }
}

// Quick Sort Helper: Partition Function
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quick Sort Algorithm with Visualization
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Visualize after partition
        printArray(arr);
        

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort Helper: Merge Function
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Visualize after merge
    printArray(arr);
    
}

// Merge Sort Algorithm with Visualization
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Function to let the user select the sorting algorithm
void sortVisualizer(vector<int>& arr) {
    int choice;
    cout << "Choose a sorting algorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Selection Sort\n";
    cout << "4. Quick Sort\n";
    cout << "5. Merge Sort\n";
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr);
            break;
        case 2:
            insertionSort(arr);
            break;
        case 3:
            selectionSort(arr);
            break;
        case 4:
            quickSort(arr, 0, arr.size() - 1);
            break;
        case 5:
            mergeSort(arr, 0, arr.size() - 1);
            break;
        default:
            cout << "Invalid choice! Exiting.\n";
            return;
    }

    cout << "Sorted Array:" << endl;
    printArray(arr);
}

int main() {
    int n;

    // User inputs the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    // User inputs the elements of the array
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Initial Array:" << endl;
    printArray(arr);

    // Call the sorting visualizer with user input
    sortVisualizer(arr);

    return 0;
}
