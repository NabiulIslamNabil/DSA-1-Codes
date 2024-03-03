#include<iostream>

using namespace std;



struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void insertValue(struct Node* current, int data){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    current->next = newNode;

}

void print(struct Node* head){
    if(!head){
        cout<<"No element in the linked list."<<endl;
    }else{
        struct Node* temp = head;
        do{
            cout<<temp->data<<"->";
            temp=temp->next;
        }while(temp!=head);
    }
}

int main(){
    head = (struct Node*)malloc(sizeof(struct Node));
    cout<<"Enter the element: ";
    int a;
    cin>>a;
    head->data = a;
    head->next = NULL;
    struct Node* current = head;
    for(int i=1; i<6; i++){
        cout<<"Enter the element: ";
        cin>>a;
        insertValue(current, a);
        current = current->next;
    }

    print(head);
}
