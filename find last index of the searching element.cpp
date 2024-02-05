//find last index of the searching element

#include<iostream>

using namespace std;

int binarySearch(int arr[], int n, int element){
    int latest, found = 0;
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == element){
            latest = mid;
            //high = mid - 1;
            //return mid;
            found = 1;
            low = mid + 1;
        }
        else if(element > arr[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    if(found == 1){
        return latest;
    }else{
        return -1;
    }
}

int main(){

    int arr[8] = {10, 14, 22, 22, 22, 23, 31, 39};
    int e = 22;
    int index = binarySearch(arr, 8, e);
    if(index != -1){
        cout<<"found at index: "<<index<<endl;
    }else{
        cout<<"Element not found";
    }
    return 0;
}

