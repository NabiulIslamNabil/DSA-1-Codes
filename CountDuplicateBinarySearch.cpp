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

int leftMostSearch(int arr[], int n, int element){
    int l = 0, r = n - 1;
    int index = -1, flag = 0;

    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]==element){
            flag = 1;
            index = mid;
            r = mid - 1;
        }else if(arr[mid]>element){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    if(flag == 1){
        return index ;
    }else{
        return flag;
    }
}

int rightMostSearch(int arr[], int n, int element){
    int l = 0, r = n - 1;
    int index = -1, flag = 0;

    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]==element){
            flag = 1;
            index = mid;
            l = mid + 1;
        }else if(arr[mid]>element){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    if(flag == 1){
        return index ;
    }else{
        return flag;
    }
}

int main(){
    int n;

    cout<<"Enter the number of elements: ";
    cin>>n;

    int arr[n];

    scanArray(arr, n);

    printArray(arr, n);

    cout<<"Duplicate Number: ";

    int dup;
    cin>>dup;

    int left = leftMostSearch (arr, n, dup);
    int right = rightMostSearch (arr, n, dup);

    int count = 0;

    if (left != -1 && right != -1) {
        count = right - left + 1;
    }


    cout<<dup<<" is found "<<count<<" times in the array";
}

/*
6
1 2 2 2 3 5
*/
