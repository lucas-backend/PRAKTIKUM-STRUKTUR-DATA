#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int data[] = {23, 10, 5, 67, 98, 3, 44};
    
    int n = sizeof(data) / sizeof(data[0]);
    
    cout << "Array sebelum diurutkan: \n";
    printArray(data, n);
    
    bubbleSort(data, n);

    cout << "\nArray setelah diurutkan (Ascending): \n";
    printArray(data, n);
    
    return 0;
}

