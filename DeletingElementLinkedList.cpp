#include<iostream>

using namespace std;

struct Node{

    int value;

    struct Node* next;

};

void print(struct Node* head){

    struct Node* current = head;

    while(current != NULL){
        cout<<current->value<<" -> ";
        current = current->next;
    }

    cout<<endl;

}

void insertValue(struct Node* previous, int n){
    struct Node* current = (struct Node*)malloc(sizeof(struct Node));
    current->value = n;
    current->next = NULL;
    previous->next = current;
    previous = current;
}

struct Node* deleteElement(struct Node* head, int index){
    struct Node* current = head;
    if(index==1){
        head = head->next;
    }else{
        for(int i=1; i<index; i++){
            if(i==index-1){
                current->next = current->next->next;
                return head;
            }
            current = current->next;
        }
    }
    return head;
}

int main(){
    int n;

    struct Node* head = (struct Node*)malloc(sizeof(struct Node*));

    cout<<"Enter the element: ";
    cin >> n;

    head->value = n;
    head -> next = NULL;

    struct Node* current = head;

    for(int i=1; i<5; i++){

        cout<<"Enter the element: ";
        cin >> n;
        insertValue(current, n);
        current = current->next;

    }

    print(head);

    cout<<"Enter the index to delete: ";
    cin >>n;

    print(deleteElement(head, n));
}
