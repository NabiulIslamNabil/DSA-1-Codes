#include<iostream>
using namespace std;

void selectionSort(int arr[], int sizee){
    int i, j, minIndex;

    for (i = 0; i < sizee - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < sizee; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        if (minIndex != i) {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }

    }
}

void scanArray(int arr[], int sizee){
    cout<<"Enter the inputs to the array: "<<endl;
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
int main(){

    int n = 10;

    int arr[n];

    scanArray(arr, n);

    //printArray(arr, n);

    selectionSort(arr, n);

    printArray(arr, n);

    return 0 ;
}

/*input
2 5 4 7 9 6 13 48 7 12
*/
