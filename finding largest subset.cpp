//finding largest subset

#include<iostream>

using namespace std;

void scanArray(int arr[], int n){

    cout<<"Enter the elements of the array: ";
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

/*void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int j = i;
        while(j>0 and arr[j-1]>arr[j]){
            swap(arr[j], arr[j-1]);
            --j;
        }
    }
}
*/

void selectionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int minimum = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minimum]){
                minimum = j;
            }
        }
        if(arr[i]!=arr[minimum]){
            swap(arr[minimum], arr[i]);
        }
    }
}

int largestSubset(int arr[], int n) {
    int maxCount = 1;

    for (int i = 0; i < n; ++i) {
        int count = 1;
        int j = i+1;

        while (j < n - 1 && arr[j] + 1 == arr[j + 1]) {
            ++count;
            ++j;
        }

        if(maxCount>count){
            maxCount = maxCount;
        }else{
            maxCount = count;
        }
    }

    return maxCount;
}


int main(){
    int n;
    cout<<"Number of elements in the array: ";
    cin>>n;
    int arr[n];
    scanArray(arr, n);
    //insertionSort(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
    int a = largestSubset(arr, n);
    cout<<"The largest subset is: "<<a<<endl;
}


/*
 6
 4 1 2 7 6 5
*/




