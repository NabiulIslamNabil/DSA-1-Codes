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
    int size = 0;
    Node* head;

    LinkedList(){
        head = nullptr;
    }

    // method to insert values into the linked list
    void insertValue(int num) {
        Node* node = new Node(num);
        node->next = head;
        head = node;
        size++;
    }

    //to delete an element from the given index
    void deleteValue(int index){
        Node* temp;
        temp = head;
        if(index>size){
            return;
        }
        else if(index == 1){
            head = head -> next;
        }
        else{
            for(int i=1; ; i++){
                if(i == index - 1){
                    head -> next = head -> next -> next;
                    break;
                }
                temp = temp -> next;
            }
        }

        size--;
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

    cout<<"The size of the linked list is: "<<linkedList.size<<endl;

    //index starts from 1
    cout<<"At which index do you want do delete: ";

    int a;
    cin>>a;

    linkedList.deleteValue(a);

    linkedList.print();

    return 0;
}

