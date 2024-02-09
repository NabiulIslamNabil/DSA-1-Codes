#include<iostream>

using namespace std;

/*void scanArray(int arr[], int n){
    cout<<"Enter the inputs to the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
*/
void printArray(int arr[], int n){
    cout<<"The elements of the array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i];
        cout<<" ";
    }
    cout<<endl;
}

int findMissing(int arr[], int n){
    int l = 0, r = n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]>mid){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return l;
}

int main(){
    int arr[9] = {0, 1, 2, 3, 4, 6, 9, 11, 15};
    printArray(arr, 9);
    int missing = findMissing(arr, 9);
    cout<<"Missing element is: "<<missing;
}


