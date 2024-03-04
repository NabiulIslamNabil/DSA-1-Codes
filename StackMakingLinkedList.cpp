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
        std::cout << "Pushed " << value << " onto the stack." << std::endl;
    }

    void pop() {
        if (last == nullptr) {
            std::cout << "Stack underflow! Cannot pop from an empty stack." << std::endl;
            return;
        }

        std::cout << "Popped " << last->data << " from the stack." << std::endl;
        last = last->next;

    }


    int top() {
        if (last == nullptr) {
            std::cout << "Stack is empty. Cannot peek." << std::endl;
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

    std::cout << "Top element: " << myStack.top() << std::endl;

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();

    return 0;
}
