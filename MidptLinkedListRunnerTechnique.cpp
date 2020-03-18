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

node* midPoint(node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    node* slow = head;
    node* fast = head -> next;

    while(fast != NULL && fast->next != NULL){//to make a jump of 2,either fast or the next node to fast should not be null
        fast = fast->next->next; //fast pointer takes 2 jumps
        slow = slow -> next; //slow pointer takes 1 jump 
    }
    //when fast reaches end of list, slow will be exactly at midpt of list.
    return slow;
}

int main() {
    node* head = NULL;
    buildList(head);
    cout << endl;
    print(head);
    node* m = midPoint(head);
    cout << m->data;
return 0;
}