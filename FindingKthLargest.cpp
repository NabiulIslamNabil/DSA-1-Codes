#include<iostream>

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

void selectionSort(int arr[], int n){
    cout<<"After selection sort: "<<endl;
    for(int i=0; i<n-1; i++){
        int maxIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]>arr[maxIndex]){
                maxIndex = j;
            }
        }
        if(maxIndex!=i){
            swap(arr[i], arr[maxIndex]);
        }
    }
}

int kthLargest(int arr[], int n, int k){
    int a = 0, kLarge = INT_MIN;
    selectionSort(arr, n);
    for(int i=0; i<n; i++){
        if(arr[i]==arr[i+1]){
            continue;
        }else{
            a++;
            if(a == k){
                kLarge = arr[i];
                break;
            }
        }
    }
    return kLarge;
}

int main(){

    int arr[6];
    scanArray(arr, 6);
    printArray(arr, 6);
    //selectionSort(arr, 6);
    //printArray(arr, 6);
    cout<<"Enter the value of k: ";
    int k;
    cin>>k;
    int a = kthLargest(arr, 6, k);
    cout<<"The "<<k<<"th largest value is: "<<a;

}
