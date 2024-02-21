#include<iostream>

using namespace std;

struct Node{

    int value;

    struct Node* next;

    struct Node* previous;

};

void add(struct Node* current, int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->value = val;
    temp->next = NULL;
    current->next = temp;
    temp->previous = current;
}

void print(struct Node* current){
    cout<<"Elements are: ";
    while(current!=NULL){

        cout<<current->value<<"-->";

        current = current->next;

    }
}


int main(){

    cout<<endl<<"__________________"<<endl;

    cout<<endl<<"Creating a Double Linked List"<<endl;

    cout<<endl<<"__________________"<<endl;

    cout<<"Enter the element to linked_list: ";
    int a;
    cin>>a;

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));

    head->value = a;
    head->previous = NULL;
    head->next = NULL;

    struct Node* current = head;
    for(int i=1; i<5; i++){
        cout<<"Enter the element to linked_list: ";
        int a;
        cin>>a;
        add(current, a);
        current = current->next;
    }

    print(head);

}
