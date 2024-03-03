#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

int isCircular(struct Node* head){

    if(head==NULL){
        return -1;
    }

    struct Node* slow = head;
    struct Node* fast = head;


    while(fast!=NULL && fast->next!=NULL){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return 1;
        }
    }

    return -1;
}

int main() {

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = nullptr;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 2;
    head->next = second;

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 3;
    second->next = third;
    third->next = nullptr;

    // Uncomment the line below to create a circular linked list
    //third->next = head;

    int x = isCircular(head);
    if (x!=-1) {
        cout << "The linked list is circular." << endl;
    } else {
        cout << "The linked list is not circular." << endl;
    }

}
