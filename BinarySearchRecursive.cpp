#include<iostream>

using namespace std;

int recursiveBinarySearch(int arr[], int low, int high, int element){

    if(low>high){
        //cout<<"Not found."<<endl;
        return -1;
    }

    int mid = (high+low)/2;
    if (arr[mid] == element) {
            return mid;
    }
    else if( arr[mid]>element){
        recursiveBinarySearch(arr, low, mid-1, element);
    }
    else{
        recursiveBinarySearch(arr, mid + 1, high, element);
    }
}

int main(){

    int arr[8] = {10, 14, 19, 22, 25, 28, 31, 39};
    int e = 28;
    int low = 0;
    int high = 7;
    int recursiveIndex = recursiveBinarySearch(arr, low, high, e);
    if(recursiveIndex != -1){
        cout<<"found at index: "<<recursiveIndex<<endl;
    }else{
        cout<<"Element not found";
    }
    return 0;
}

