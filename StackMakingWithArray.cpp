#include<iostream>

using namespace std;

const int s = 100;

int t = -1;

class Stack{
private:
    int arr[s];
    int t;

public:
    Stack(){
        t = -1;
    }
    void push(int a){
        if(t==s-1){
            cout<<"Stack Overflow"<<endl;
        }else{
            t++;
            arr[t] = a;
        }
    }

    int top(){
        if(t!=-1){
            return arr[t];
        }
    }

    void pop(){
        if(t!=-1){
            cout<<"Popped "<<arr[t]<<endl;
            t--;
        }else{
            cout<<"Not enough element."<<endl;
        }
    }

    int size(){
        return t+1;
    }

};
int main(){
    Stack s;
    s.push(1);
    s.push(5);
    s.push(3);
    s.push(2);
    s.push(4);
    s.pop();
    int e = s.top();
    cout<<e<<endl;
    s.pop();
    cout<<s.top();
}

