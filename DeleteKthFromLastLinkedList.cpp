#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void print(struct Node* head){
    struct Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

void entry(struct Node* current, int data){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    current->next = newNode;
}

struct Node* deleteKth(struct Node* head, int s, int k){

    struct Node* temp = head;

    int n = s-k;
    int i = 1;

    if(k==1){
        for(int i=1; i<s; i++){
            if(i==s-1){
                temp->next = NULL;
            }
            temp = temp->next;
        }
        return head;
    }else if(k==s){
        head = head->next;
        return head;
    }else if(k>s){
        cout<<"Out of bounds."<<endl;
        cout<<"Operation couldn't be done"<<endl;
        return head;
    }else{
        while(i<n){
        temp = temp->next;
        i++;
    }
        temp->next = temp->next->next;
        return head;
    }
}

int main(){
    int s = 0;
    int a;
    cout<<"Enter the element: ";
    cin>>a;

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));

    head->data = a;
    head->next = NULL;
    s++;

    struct Node* current = head;
    do{
        cout<<"Enter the element: ";
        cin>>a;
        if(a!=-1){
            entry(current, a);
            current = current->next;
            s++;
        }

    }while(a!=-1);

    print(head);
    //cout<<s;

    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

    head = deleteKth(head, s, k);
    print(head);
}

