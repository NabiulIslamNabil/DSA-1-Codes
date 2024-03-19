#include<iostream>

using namespace std;

int size = 100, count = 0;

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void push(int a){
    if(count>=size){
        cout<<"Stack Overflow"<<endl;
    }else{
        struct Node* newNode = new Node();
        cout<<"Pushed "<<a<<" to the stack"<<endl;
        newNode->data = a;
        newNode->next = head;
        head = newNode;
        count++;
    }
}

void pop(){
    if(head==NULL){
        cout<<"Stack Underflow";
    }else{
        cout<<"Popped "<<head->data<<endl;
        head = head->next;
        count--;
    }
}

int top(){
    return head->data;
}

int stackSize(){
    return count;
}

void display(){
    struct Node* current = head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

int main(){
    push(5);
    push(4);
    push(1);
    cout<<"Size: "<<stackSize()<<endl;
    display();
    pop();
    cout<<"Size: "<<stackSize()<<endl;
    cout<<"Top: "<<top()<<endl;
    pop();
    pop();
    pop();
}
