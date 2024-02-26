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
        current=current->next;
    }
    cout<<endl;
}

int searchElement(struct Node* head, int element){
    int pos = -1;
    struct Node* current = head;
    int i=1;
    while(current != NULL){
        if(current->data==element){
            pos = i;
        }
        i++;
        current = current->next;
    }
    return pos;
}

void entry(struct Node* current, int data){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    current->next = newNode;
}

int main(){
    cout<<"Enter the element: ";
    int a;
    cin>>a;
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = a;
    head->next = NULL;

    struct Node* current = head;
    for(int i=1; i<5; i++){
        cout<<"Enter the element: ";
        cin>>a;
        entry(current, a);
        current=current->next;
    }
    print(head);

    cout<<"Enter the element you want to search: ";
    cin>>a;
    int n = searchElement(head, a);
    if(n!=-1){
        cout<<"Found at index no. "<<n;
    }else{
        cout<<"Not found";
    }
}
