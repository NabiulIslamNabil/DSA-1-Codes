#include<iostream>

using namespace std;

int perfectSquareCheck(int n, int low, int high){
    if(low>high){
        return -1;
    }else{
        int mid = (high + low)/2;
        if((mid * mid) == n){
            return 1;
        }
        else if((mid*mid)>n){
            perfectSquareCheck(n, low, mid-1);
        }
        else{
            perfectSquareCheck(n, mid+1, high);
        }
    }
}

int main(){
    cout<<"Enter the input: ";
    int n;
    cin>>n;
    int low = 1, high = n;
    int isSquare = perfectSquareCheck(n, low, high/2);
    if(isSquare != -1){
        cout<<n<<" is a perfect square";
    }else{
        cout<<n <<" is not a perfect square";
    }
}
