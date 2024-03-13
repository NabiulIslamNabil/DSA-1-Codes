#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* last;

public:
    Stack() {
        last = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = last;
        last = newNode;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    void pop() {
        if (last == nullptr) {
            cout << "Stack underflow! Cannot pop from an empty stack." << endl;
            return;
        }

        cout << "Popped " << last->data << " from the stack." << endl;
        last = last->next;

    }


    int top() {
        if (last == nullptr) {
            cout << "Stack is empty. Cannot peek." <<endl;
            return -1;
        }
        return last->data;
    }

    bool isEmpty() {
        return last == nullptr;
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Top element: " << myStack.top() << endl;

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();

    return 0;
}
