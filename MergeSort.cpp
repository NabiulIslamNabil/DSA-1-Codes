#include<iostream>

using namespace std;

void mergeArr(int arr[], int l, int mid, int r){

    int n1 = mid - l + 1;
    int n2 = r - mid ;

    int a[n1], b[n2];

    for(int i=0; i<n1; i++){
        a[i] = arr[l+i];
    }
    for(int i=0; i<n2; i++){
        b[i] = arr[mid+1+i];
    }

    int x = 0;
    int y = 0;
    int z = l;

    while(x<n1 && y<n2){
        if(a[x]<b[y]){
            arr[z] = a[x];
            x++;
            z++;
        }else{
            arr[z] = b[y];
            y++;
            z++;
        }
    }
    while(x<n1){
        arr[z] = a[x];
        x++;
        z++;
    }
    while(y<n2){
        arr[z] = b[y];
        y++;
        z++;
    }
}

void mergeSort(int arr[], int l, int r){
    int mid = (l+r)/2;
    if(l<r){

       mergeSort(arr, l, mid);
       mergeSort(arr, mid+1, r);

       mergeArr(arr, l, mid, r);

    }

}

void scanArray(int arr[], int n){
    cout<<"Enter the elements to the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}

void printArray(int arr[], int n){
    cout<<"The elements of the array are: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    scanArray(arr, n);
    printArray(arr, n);

    mergeSort(arr, 0, n-1);
    printArray(arr, n);

    return 0;
}
