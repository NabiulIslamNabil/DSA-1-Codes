#include<iostream>

using namespace std;

struct Node{
    int value;
    struct Node* next;
};

void print(struct Node* head){

    struct Node* current = head;

    while(current!=NULL){
        cout<<current->value<<" -> ";
        current = current -> next;
    }
    cout<<endl;

}

void entry(struct Node* prev, int n){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = n;
    newNode->next = NULL;
    prev->next = newNode;
    prev = newNode;

}

struct Node* insertion(struct Node* head, int index, int element){

    struct Node* current = head;

    if(index == 1){
         struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
         temp->value = element;
         temp->next = head;
         return temp;
    }else{
        for(int i = 1; i<index-1; i++)
        {
            current = current->next;
        }

        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->value = element;
        temp->next = current->next;
        current->next = temp;

        return head;

    }

}

int main(){
    int n;

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));

    cout<<"Enter the element: ";
    cin >> n;

    head->value = n;
    head->next = NULL;

    struct Node* current = head;

    for(int i=1; i<5; i++){
        cout<<"Enter the element: ";
        cin>>n;
        entry(current, n);
        current = current->next;
    }

    print(head);

    int element, index;
    cout<<"Enter the element that you want to insert: ";
    cin>>element;

    cout<<"Enter its index no. ";
    cin>>index;

    head = insertion(head, index, element);

    print(head);
}
