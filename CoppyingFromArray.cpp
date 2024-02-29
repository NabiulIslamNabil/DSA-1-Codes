#include<iostream>

using namespace std;

struct Node{

    int data;
    struct Node* next;

};

void insertVal(struct Node* current, int data){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    current->next = newNode;

}

void print(struct Node* head){

    struct Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;

}

void printArray(int arr[], int n){

    cout<<"Elements of the array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

void scanArray(int arr[], int n){

    cout<<"Enter the elements to the array: "<<endl;
    for(int i=0; i<n; i++){
        cout<<"Element: ";
        cin>>arr[i];
    }

}

int main(){

    int n;
    cout << "Number of elements: ";
    cin >> n;

    int arr[n];
    scanArray(arr, n);
    printArray(arr, n);

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;

    struct Node* current = head;

    for(int i=1; i<n; i++){
        insertVal(current, arr[i]);
        current = current->next;
    }

    print(head);

}
