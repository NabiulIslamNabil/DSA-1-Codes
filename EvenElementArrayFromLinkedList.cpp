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

int* even(struct Node* head, int& count)
{
    struct Node* current = head;

    count = 0;
    while(current != NULL)
    {
        if(current->value % 2 == 0)
        {
            count++;
        }
        current = current->next;
    }

    int *arr = new int[count];

    current = head;
    int i = 0;

    while(current != NULL){
        if(current->value % 2 == 0){
            arr[i++] = current->value;
        }
        current = current->next;
    }

    return arr;
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

    for (int i=1; i<8; i++){
        cout<<"Enter the elements to the linked list: ";
        cin >> n;
        insertValue(current, n);
        current = current->next;
    }

    print(head);

    int count;

    int *arr = even(head, count);

    if(count!=0){

         cout<<"Even elements are: "<<endl;

         for (int i = 0; i < count; i++){
         cout << arr[i] << " ";
        }
    }else{
        cout<<"No even elements in the linked list."<<endl;
    }

}

