#include<iostream>

using namespace std;

int binarySearch(int arr[], int n, int element){

    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == element){
            return mid;
        }
        else if(element > arr[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){

    int arr[8] = {10, 14, 19, 22, 25, 28, 31, 39};
    int e = 19;
    int index = binarySearch(arr, 8, e);
    if(index != -1){
        cout<<"found at index: "<<index<<endl;
    }else{
        cout<<"Element not found";
    }
    return 0;
}
