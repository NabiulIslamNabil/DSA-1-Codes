#include<iostream>
using namespace std;


void scanArray(int arr[], int n){
    cout<<"Enter the inputs to array: "<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
}

void printArray(int arr[], int n){
    cout<<"The elements of the array are: "<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
        if(i == n-1){
            cout<<endl;
        }
    }
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

int main(){

    int n = 10;

    int arr[n];

    scanArray(arr, n);

    printArray(arr, n);

    insertionSort(arr, n);

    printArray(arr, n);

    return 0 ;
}
/*input
2 5 4 7 9 6 13 48 7 12
*/


