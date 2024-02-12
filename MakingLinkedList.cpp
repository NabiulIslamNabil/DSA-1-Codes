#include<iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val){
    this->value = val;
    next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList(){
        head = nullptr;
    }

    // method to insert values into the linked list
    void insertValue(int num) {
        Node* node = new Node(num);
        node->next = head;
        head = node;
    }

    // to see elements of the linked list
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;

    int n;

    //run a loop till user inputs negative integer

    while(true){
        cout<<"Enter the value that you want to add to linked list, negative value to exit: ";
        cin>>n;
        if(n<0){
            break;
        }
        linkedList.insertValue(n);
    }

    linkedList.print();

    return 0;
}
