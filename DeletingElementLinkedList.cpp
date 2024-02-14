#include<iostream>

using namespace std;

int listSize = 0;

struct Node{

    int value ;
    struct Node* next;

};

void scan(struct Node* head){
    int a = 1, n;
    while(true){
        cout<<"Enter the element to the linked list(-1 or less to exit): ";
        cin>>n;
        if(n<0){
            break;
        }
        if(a==1){
            head->value = n;
            head->next = NULL;
        }else{
            struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
            temp ->value = n;
            temp ->next = NULL;

            struct Node* current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current ->next = temp;
        }
        a++;
        listSize++;
    }
}

void print(struct Node* head){

    struct Node* temp = head;
    while(temp!=NULL){
        cout<<temp->value <<" -> ";
        temp = temp -> next;
    }
    cout<<endl;

}

void deleteElement(struct Node* head, int index){
    if(index>listSize)
    {
        return;
    }
    else if(index == 1)
    {
        head = head -> next;
    }
    else
    {
        struct Node* temp = head;
        for(int i=1; ; i++)
        {
            if(i == index - 1)
            {
                temp -> next = temp -> next -> next;
                break;
            }
            temp = temp -> next;
        }
    }

    listSize--;
}

int main(){

    struct Node* head;
    head = (struct Node*)malloc(sizeof(struct Node));

    scan(head);

    print(head);

    cout<<"Size of Linked List: "<<listSize<<endl;

    cout<<"Enter the index of the element that you want to delete: ";

    int index;
    cin >> index;

    deleteElement(head, index);
    print(head);
}
