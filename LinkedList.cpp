#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    //Constructor
    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtHead(node*&head, int data) { //passing by reference
    node* n = new node(data);
    n -> next = head;
    head = n;
}

int length(node* head) {
    int len=0;
    while (head!=NULL){
        head = head -> next;
        len = len+1;
    }
    return len;
}

void insertAtTail(node*&head,int data){
    if (head==NULL){
        head = new node(data);
        return;
    }
    node* tail = head;
    while (tail -> next != NULL) {
        tail = tail -> next;
    }
    tail -> next = new node(data);
    return;
}
void insertInMiddle(node*&head, int data, int p){
    if(head==NULL || p==0) {
        insertAtHead(head, data);
    }
    else if(p>length(head)){
        insertAtTail(head, data);
    }
    else {
       //Insert at middle
        //take p-1 jumps
        int jump=1;
        node* temp = head;
        while (jump <= p-1) {
            temp = temp -> next;
            jump += 1;
        }
        //now temp is at correct place
        node* n = new node(data);
        n -> next = temp -> next;
        temp -> next = n; 
    }
}

void print(node* head) {
    node* temp = head;
    while(temp!=NULL) {
        cout << temp -> data<<"->";
        temp = temp -> next;
    }
}

void deleteAtHead(node*&head){
    if (head==NULL){
        return;
    }
    node* temp = head;
    head = head -> next;
    delete temp; //frees up the memory stored by original head
    return;
}

void deleteAtTail(node*&head){
    node* prev = NULL;
    node* temp = head;
    while(temp -> next != NULL) {
        prev = temp;
        temp = temp -> next;
    }
    delete temp;
    prev -> next = NULL;
    return;
}

void deleteInMiddle(node*&head, int p){
    node* temp = head;
    node* prev = NULL;
    int jump = 0;
    if (p == 1){
        deleteAtHead(head);
    }
    while(jump<p-1) {
        jump += 1;
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = temp -> next;
    delete temp;
    return;
}

bool searchRecursive(node* head, int key) {
    if(head==NULL) {
        return false;
    }
    //Rec Case
    if(head -> data == key){
        return true;
    }
    else {
        return searchRecursive(head -> next, key);
    }
}

bool searchIterative(node* head, int key){
    while (head!=NULL){
        if(head->data == key){
            return true;
        }
        head = head -> next;
    }
    return false;
}

//taking linkedlist as input
void buildList(node*&head){
    int data;
    cin>>data; //data is the first data
    while (data != -1){
        insertAtTail(head,data);
        cin>>data;
    }
}

int main() {
    node* head = NULL;
    /*
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtTail(head,6);
    insertInMiddle(head,2,3);
    //deleteAtHead(head);
    //deleteAtTail(head);
    deleteInMiddle(head,3);
    print(head);
    if(searchRecursive(head,4)){
        cout<<"element is present";
    }
    else{
        cout<<"not present";
    }
    */
    buildList(head);
    print(head);
return 0;
}