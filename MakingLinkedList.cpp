#include<iostream>

using namespace std;

struct Node
{

    int value;

    struct Node* next;

};

void print(struct Node* head)
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->value<<" -> ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertValue(struct Node *prev, int value) {

    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    prev->next = newNode;

}

int main()
{
    struct Node* head;
    head = (struct Node*)malloc(sizeof(struct Node));

    cout<<"Enter the element to the linked list: ";

    int n;

    cin>>n;

    head -> value = n;
    head -> next = NULL;

    struct Node *current = head;

    for (int i=1; i<5; i++){
        cout<<"Enter the elements to the linked list: ";
        cin >> n;
        insertValue(current, n);
        current = current->next;
    }

    print(head);

}
