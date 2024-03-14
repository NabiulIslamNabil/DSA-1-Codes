#include<iostream>

using namespace std;


void scanArray(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        cout<<"Enter the inputs to array: ";
        cin>>arr[i];
    }
}

void printArray(int arr[], int n){
    cout<<"The elements of the array are: "<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout <<endl;
}

int Partition(int arr[], int start, int end){
    int pivot = arr[end];

    int i = start - 1;

    for(int j=start; j<end; j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

        i++;
        int temp = arr[i];
        arr[i] = arr[end];
        arr[end] = temp;

    return i;
}

void quickSort(int arr[], int start, int end){
    if(end<=start){
        return;
    }

    int pivot = Partition(arr, start, end);

    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot+1 , end);
}

int main(){
    int n = 10;
    int arr[n];
    scanArray(arr, 10);
    arr[n-1] = INT_MAX;

    printArray(arr, 10);

    quickSort(arr, 0, n-1);
    printArray(arr, n-1);
}




