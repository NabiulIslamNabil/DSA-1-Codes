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

void scan(struct Node* head)
{

    int n;
    int a = 1;
    while(true)
    {
        cout<<"Enter elements to the linked list (-1 or less to exit): ";
        cin >> n;
        if(n<0)
        {
            break;
        }
        if(a==1)
        {
            head->value = n;
            head->next = NULL;
        }
        else
        {
            struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
            temp->value = n;
            temp->next = NULL;
            struct Node* current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = temp;
        }

        a++;
    }

}

int main()
{
    struct Node* head;
    head = (struct Node*)malloc(sizeof(struct Node));

    scan(head);

    print(head);

}
