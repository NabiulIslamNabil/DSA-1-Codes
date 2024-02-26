#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void print(struct Node* head){
    struct Node* current = head;
    while(current != NULL){
        cout<<current->data<<"->";
        current = current->next;
    }
    cout<<endl;
}

void entry(struct Node* current, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    current->next = newNode;
}

struct Node* combine(struct Node* head1, struct Node* head2){
    struct Node* temp = head1;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
};

int main(){
    int a;
    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    cout<<"First Linked List: "<<endl;
    cout<<"Enter the element: ";
    cin>>a;
    head1->data = a;
    head1->next = NULL;

    struct Node* current = head1;
    for(int i=1; i<5; i++){
        cout<<"Enter the element: ";
        cin>>a;
        entry(current, a);
        current = current->next;
    }

    cout<<"First Linked List: "<<endl;
    print(head1);

    cout<<"Second Linked List: "<<endl;
    cout<<"Enter the element: ";
    cin>>a;
    head2->data = a;
    head2->next = NULL;

    struct Node* current2 = head2;
    for(int i=1; i<5; i++){
        cout<<"Enter the element: ";
        cin>>a;
        entry(current2, a);
        current2 = current2->next;
    }
    cout<<"Second Linked List: "<<endl;
    print(head2);

    cout<<"...Joining two linked list..."<<endl;

    struct Node* head;
    head = combine(head1, head2);

    cout<<"...After combining..."<<endl;

    print(head);
}
