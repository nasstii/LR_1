#include <iostream>
#include <cstdlib>
#include <ctime>
clock_t currentTime;
using namespace std;

template <typename T> //Creating a template
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T> 
int divide(T arr[], int l, int h) {
    T a = arr[h]; // Select the rightmost element as the main one
    int i = l - 1;
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] < a) { // Checking for equality of the current element is less than or equal to the main one
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[h]);
    return (i + 1);
}

template <typename T>
int randomDivide(T arr[], int l, int h) {
    srand(time(0));
    int random = l + rand() % (h - l);
    std::swap(arr[random], arr[h]);
    return divide(arr, l, h);
}

template <typename T>
void quickSort(T arr[], int l, int h) {
    if (l < h) {
        int a = randomDivide(arr, l, h); // Recursively sorting the elements before and after splitting
        quickSort(arr, l, a - 1);
        quickSort(arr, a + 1, h);
    }
}

template <typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // Swapping the elements
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        T a = arr[i];
        int j = i - 1; //one position ahead of their current position
        while (j >= 0 && arr[j] > a) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = a;
    }
}
   


int main() {
    int n = 0;
    int a = 0;
    double start = 0; // for time
    double end = 0; // for time
    double timeTaken = 0; // for time
    cout << "Enter the length of the array: ";
    cin >> n; //Entering the length of the array
    int* arr = new int[n];

    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Random numbers in a given range
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "What sort of sorting do you want to use? (1 - quickSort; 2 - bubbleSort; 3 - insertionSort ";
    cin >> a; //choosing a sort
    cout << endl;
    if (a == 1) {
        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();
        double timeTaken = double(end - start) / CLOCKS_PER_SEC;
        std::cout << "time spent Quick Sort for int: " << timeTaken << " sec" << std::endl;
    }
    if (a == 2) {
        clock_t start = clock();
        bubbleSort(arr, n);
        clock_t end = clock();
        double timeTaken = double(end - start) / CLOCKS_PER_SEC;
        std::cout << "time spent Quick Sort for int: " << timeTaken << " sec" << std::endl;
    }
    if (a == 3) {
        clock_t start = clock();
        insertionSort(arr, n);
        clock_t end = clock();
        double timeTaken = double(end - start) / CLOCKS_PER_SEC;
        std::cout << "time spent Quick Sort for int: " << timeTaken << " sec" << std::endl;
    }
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) { //displaying an array on the screen
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}