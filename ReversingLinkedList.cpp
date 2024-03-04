#include<iostream>

using namespace std;

struct Node{
    int value;
    struct Node* next;
};

void insertValue(struct Node* prev, int a){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = a;
    newNode->next = NULL;
    prev->next = newNode;
}

void print(struct Node* head){
    struct Node* current = head;
    while(current!=NULL){
        cout<<current->value<<"->";
        current = current->next;
    }
    cout<<endl;
}

struct Node* reverseList(struct Node* head){
    struct Node* slow = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fast = (struct Node*)malloc(sizeof(struct Node));

    fast = NULL;
    slow = NULL;

    while(head!=NULL){
        fast = head->next;
        head->next = slow;
        slow = head;
        head = fast;
    }
    head = slow;
    return head;
}

int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    cout<<"Enter the element: ";
    int a;
    cin>>a;
    head->value = a;
    head->next = NULL;

    struct Node* current = head;
    for(int i=1; i<5; i++){
        cout<<"Enter the element: ";
        cin>>a;
        insertValue(current, a);
        current=current->next;
    }
    print(head);

    head = reverseList(head);

    print(head);
}
