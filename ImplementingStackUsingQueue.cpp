//Implementing Stack Using Queue

#include<iostream>

using namespace std;

class Queue{
    int first, last, arr[100];
public:
    Queue(){
        first = -1;
        last = -1;
    }

    void push(int a){
        if(last==-1){
            first = (first+1)%100;
            last = (last+1)%100;
            arr[last]=a;
        }else{
            last = (last+1)%100;
            arr[last]=a;
        }
    }
    int pop(){
        int a;
        if(last!=-1){
            if(first == last){
                a = arr[first];
                first = -1;
                last = -1;
                return a;
            }else{
                a = arr[first];
                first = (first+1)%100;
                return a;
            }
        }else{
            cout<<"Underflow"<<endl;
            return -1;
        }
    }

    int top(){
        cout<<"Top is "<<arr[last]<<endl;
        return arr[last];
    }
    bool isEmpty(){
        return last==-1;
    }
    int firstElement(){
        return arr[first];
    }
};

class Stack{
    Queue q1, q2;
public:
    void push(int x){
        while(!q1.isEmpty()){
            q2.push(q1.pop());
        }
        q1.push(x);
        while(!q2.isEmpty()){
            q1.push(q2.pop());
        }
    }

    int pop(){
       int a = q1.pop();
       cout<<a<<endl;
       return a ;
    }

    int top(){
        cout<<q1.firstElement();
        return q1.firstElement();
    }

    bool isEmpty(){
        return q1.isEmpty();
    }
};

int main(){

    Stack s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(6);
    s.push(8);
    s.pop();
    s.pop();
    s.top();
}
