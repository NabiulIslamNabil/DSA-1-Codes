//finding the median of an array

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
    for(int i=0; i<n; i++){
        int minimum = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minimum]){
                minimum = j;
            }
        }
        if(i != minimum){
            int temp = arr[minimum];
            arr[minimum] = arr[i];
            arr[i] = temp;
        }
    }
}

int medianFinder(int arr[], int n){
    return arr[n/2];
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    //taking input
    scanArray(arr, n);
    //sorting array
    selectionSort(arr, n);
    //printing array
    //printArray(arr, n);

    int median = medianFinder(arr, n);

    cout<<"Median value is: "<<median;
}
/*inputs
11
1 3 2 0 10 7 4 8 9 6 5
Output: 5
*/

