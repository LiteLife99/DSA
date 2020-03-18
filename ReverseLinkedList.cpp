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

void reverse(node*&head){
    node* c = head; //c is current pointer
    node* p = NULL; //p is the previous pointer
    node* n;//n is the next pointer

    while(c != NULL){
        //save the next node
        n = c -> next;
        //make the current node point to prev
        c -> next = p;
        //update prev and current
        p = c;
        c = n;
    }
    head = p; //since now current is null
}

void print(node* head) {
    node* temp = head;
    while(temp!=NULL) {
        cout << temp -> data<<"->";
        temp = temp -> next;
    }
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
    buildList(head);
    reverse(head);
    print(head);
}