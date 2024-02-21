#include<iostream>

using namespace std;

struct Node{

    int value;

    struct Node* next;

    struct Node* previous;


};

void add(struct Node* current, int value){

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->value = value;

    current->next = temp;

    temp->previous = current;

    temp->next = NULL;

}

struct Node* insertElement(struct Node* current, int value, int index){

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->value = value;

    if (index == 1) {
        temp->previous = NULL;
        temp->next = current;
        current->previous = temp;
        return temp;
    } else {

        for (int i = 1; i < index - 1; i++) {
            current = current->next;
        }

        temp->next = current->next;
        temp->previous = current;

        if (current->next != NULL) {
            current->next->previous = temp;
        }

        current->next = temp;
        return current;
    }
}

void print(struct Node* head){

    struct Node* temp = head;

    cout<<"The elements of the linked list are: ";

    while(temp != NULL){

        cout<<temp->value<<"->";

        temp = temp->next;
    }

    cout<<endl;

}

int main(){

    cout<<endl<<"__________________"<<endl;

    cout<<endl<<"Creating a Double Linked List"<<endl;

    cout<<endl<<"__________________"<<endl;

    cout<<"Enter the element to linked_list: ";
    int a;
    cin>>a;

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->previous = NULL;
    head->next = NULL;
    head->value = a;

    struct Node* current = head;

    for(int i=1; i<5; i++){

        cout<<"Enter the element to linked_list: ";
        int a;
        cin>>a;

        add(current, a);

        current = current->next;

    }

    print(head);

    //size is 5
    cout<<"Enter the index number(less than size+2): ";
    int n;
    cin >> n;
    cout<<"Enter the element you want to add: ";

    cin >> a;

    head = insertElement(head, a, n);

    cout<<"Insertion Completed."<<endl;

    print(head);

}
