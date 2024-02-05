#include<iostream>

using namespace std;

void scanArray(int arr[], int n){
    cout<<"Enter the elements to the array: ";
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

int rootSquare(int n, int low, int high){

    while(low<=high){
        int mid = (low + high)/2;
        if(mid*mid == n){
            return mid;
        }else if(mid * mid > n){
            high = mid - 1 ;
        }else{
            low = mid + 1;
        }
    }
    return -1 ;
}

int main(){
    int n;

    cout<<"Enter the square number: ";

    cin >> n;

    int low = 0;
    int high = n;

    int a = rootSquare(n, low, high);

    if( a != -1){
        cout<<"The square root of "<<n<<" is "<<a;
    }else{
        cout<<"The input "<<n<<" is not a perfect square";
    }

    return 0;
}
