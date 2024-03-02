#include<iostream>
#include<stack>

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

int palindromeCheck(struct Node* head){
    struct Node* slow = head;
    stack<int> s;
    while(slow!=NULL){
        s.push(slow->value);
        slow = slow->next;
    }

    struct Node* current = head;
    while(current!=NULL){
        int i = s.top();
        s.pop();
        if(current->value!=i){
            return -1;
        }
        current = current->next;
    }

    return 1;

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

    int x = palindromeCheck(head);

    if(x!=-1){
        cout<<"The given Linked list is a palindrome. "<<endl;
    }else{
        cout<<"The given linked list is not a palindrome. "<<endl;
    }

}
