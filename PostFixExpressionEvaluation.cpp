#include<iostream>
#include<climits>

using namespace std;

class MyStack{
    int arr[100];
    int last;
    int size;
public:
    MyStack(){
        last = -1;
        size = 0;
    }

    void push(int a){
        if(size>=99){
            cout<<"Stack Overflow."<<endl;
        }else{
            last++;
            arr[last] = a;
            size++;
        }
    }

    void pop(){
        if(last!=-1 && size !=0){
            last--;
            size--;
        }else{
            cout<<"Stack Underflow."<<endl;
        }
    }

    int top(){
        if(last!=-1){
            return arr[last];
        }else{
            return INT_MIN;
        }
    }

    int stackSize(){
        return size;
    }

    bool empty(){
        return size == 0;
    }
};

int evaluatePostfix(char arr[], int n)
{
    MyStack s;
    for(int i=0; i<n; i++){
        if(arr[i]>='0' && arr[i]<='9'){
            int a = arr[i]-'0';
            s.push(a);
        }else{
            switch(arr[i]){
            case '+':{
                if (s.stackSize() < 2) return INT_MIN;
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                s.push(op1 + op2);
                break;
            }case '-':{
                if (s.stackSize() < 2) return INT_MIN;
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                s.push(op1 - op2);
                break;
            }case '*':{
                if (s.stackSize() < 2) return INT_MIN;
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                s.push(op1 * op2);
                break;
            }case '/':{
                if (s.stackSize() < 2) return INT_MIN;
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                if (op2 == 0) return INT_MIN;
                s.push(op1 / op2);
                break;
            }
            default:
                return INT_MIN;
            }
        }
    }
    return s.top();
}

int main(){
    int n;
    cout<<"Number of characters in expression: ";
    cin>>n;
    char arr[n];

    cout<<"Enter the postfix expression: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int value = evaluatePostfix(arr, n);
    if(value!=INT_MIN){
        cout<<"The value of the given postfix expression is: "<<value<<endl;
    }
}
