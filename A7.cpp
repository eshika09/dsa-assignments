#include<iostream>
using namespace std;
class Node{
    public:
    char val;
    Node* next;
    Node(char data){
    val=data;
    next=NULL;
    }
};
class LinkedList{
    public: 
    Node* head;
    LinkedList(){
        head=NULL;
    }
    void addAtBeg(char val){
     Node* newnode=new Node(val);
     newnode->next=head;
     head=newnode;
    }
    void append(char val){
        Node* newnode= new Node(val);
        if(head==NULL){
            head=newnode;
            return;
        }Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }temp->next=newnode;
    }
    void addAtPos(char val, int pos){
        if(pos==0){
            addAtBeg(val);
            return;
        }
        Node* newnode=new Node(val);
        Node* temp=head;
        int currpos=0;
        while(currpos!=pos-1){
            temp=temp->next;
            currpos++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }cout<<NULL<<endl;
    }
    void displayMore(){
        Node* temp=head; 
        while(temp!=NULL){
            cout<<"Address: "<<temp;
            cout<<"Value: "<<temp->val;
            cout<<"Next Address: "<<temp->next;
        }
    }
    void deleteAtStart(){
        Node* temp=head;
        head=head->next;
        free(temp);
    }
    void deleteAtEnd(){
        Node* secondlast=head;
        while(secondlast->next->next!=NULL){
            secondlast=secondlast->next;
        }Node* temp=secondlast->next;
        secondlast->next=NULL;
        free(temp);
    }
    void deleteAtPos(int pos){
        if(pos==0){
            deleteAtStart();
            return;
        }
        Node* prev=head;
        int currpos=0;
        while(currpos!=pos-1){
            prev=prev->next;
            currpos++;
        }
        Node* temp=prev->next;
        prev->next=prev->next->next;
        free(temp);
    }
   int getlength(){
    Node* temp=head;
    int length=0;
    if(head==NULL){
        return 0;
    }
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }return length;
   }
};
int main(){LinkedList ll;
ll.addAtBeg('A');
ll.append('B');
ll.addAtPos('C', 1);
ll.display();

cout<<"Detailed list info: "<<endl;
ll.displayMore();

ll.deleteAtStart();
ll.deleteAtEnd();
ll.deleteAtPos(0);
cout<<"List elements after removal: ";
ll.display();

    return 0;
}