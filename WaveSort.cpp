#include<iostream>
using namespace std;

void swap(int arr[], int a, int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
}

void scanArray(int arr[], int sizee){
    cout<<"Enter the inputs to the array: ";
    for(int i=0;i<sizee;i++){
        cin>>arr[i];
    }
}

void printArray(int arr[], int sizee){
    cout<<"The elements of the array: "<<endl;
    for(int i=0;i<sizee;i++){
        cout<<arr[i];
        cout<<" ";
    }
    cout<<endl;
}

void selectionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int mini = i;
        for(int j=i+1; j<n; j++){
            if(arr[mini]>arr[j]){
                mini = j ;
            }
        }
        if(mini != i){
            int temp = arr[i];
            arr[i] = arr[mini];
            arr[mini] = temp;
        }
    }
}

void waveSort(int arr[], int n){
    for(int i = 0; i < n-1; i+=2){
        if(i > 0 && arr[i - 1] > arr[i])
            swap(arr, i, i-1);
            if(i < n-1 && arr[i + 1] > arr[i])
            swap(arr, i, i+1);
        }
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];

    scanArray(arr, n);

    selectionSort(arr, n);

    printArray(arr, n);

    waveSort(arr, n);

    printArray(arr, n);
}
/*
7
10 90 49 2 1 5 23
*/

