#include <iostream>

using namespace std;

void scanArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int arr[], int n, int k) {
    for (int i = 0; i < k; i++) {
        int current = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    scanArray(arr, n);

    int k;
    cin >> k;

    insertionSort(arr, n, k);

    printArray(arr, k);

    return 0;
}


/*
6
Given array: 6 7 5 3 9 1
k = 3
Output: 5 6 7
*/
