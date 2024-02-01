//finding nth smallest element
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

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int current = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>current){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = current;
    }

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    int k;
    //taking input
    scanArray(arr, n);
    cout<<"N: ";
    cin>>k;

    //printArray(arr, n);

    insertionSort(arr, n);

    cout<<k<<"th Minimum is: "<<arr[k-1];
}

/*inputs
8
10 3 6 9 2 4 15 23
N = 4
Output: 6
*/
