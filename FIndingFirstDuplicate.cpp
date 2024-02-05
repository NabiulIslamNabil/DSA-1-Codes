//find_first_element_occurence

#include<iostream>

using namespace std;

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

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int j = i-1;
        while(j>=0 and arr[j+1]<arr[j]){
            swap(arr[j+1], arr[j]);
            --j;
        }
    }

}

int binarySearch(int arr[], int n, int element){
    int index, found = 0;
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == element){
            index = mid;
            found = 1;
            high = mid -1;
        }
        else if(element > arr[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    if(found == 1){
        return index;
    }else{
        return -1;
    }
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];

    scanArray(arr, n);

    cout<<"Enter the element you want to search: ";
    int e;
    cin >> e;

    insertionSort(arr, n);
    printArray(arr, n);

    int index = binarySearch(arr, n, e);
    if(index != -1){
        cout<<"found at index: "<<index<<endl;
    }else{
        cout<<"Element not found";
    }
    return 0;
}
/*
8
10 14 2 2 14 23 14 39
*/

