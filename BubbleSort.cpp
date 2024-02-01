#include<iostream>
using namespace std;

void bubbleSort(int arr[], int sizee){

    cout<<"After Bubble Sorting: "<<endl;
    for(int i = 0; i<sizee; i++){
        for(int j = 0; j<sizee - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
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

    bubbleSort(arr, n);

    printArray(arr, n);

    return 0 ;
}

/*input
2 5 4 7 9 6 13 48 7 12
*/
