#include <iostream>
using namespace std;

void deleteEnd();
void print();

struct node{
    int data;
    node *next;
};
node *head=NULL;

int main(){
    int choice;

    node *node1, *node2, *node3, *node4;
    node1=new node;
    node2=new node;
    node3=new node;
    node4=new node;

    node1->data=1;
    node2->data=2;
    node3->data=3;
    node4->data=4;

    head=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=NULL;
    
    do{
        cout<<endl<<"*************************"<<endl;
        cout<<"1- Delete"<<endl;
        cout<<"2- Print"<<endl;
        cout<<"3- Exit"<<endl;
        cout<<"*************************"<<endl;
        
        cout<<"Enter: ";
        cin>>choice;

        switch(choice){
            case 1: deleteEnd(); break;
            case 2: print(); break;
            default: break;
        }
    }while(choice<3);
    return 0;
}

void deleteEnd(){
    node *temp, *temp1;

    if(head->next!=NULL){
        temp=head;
        while(temp->next!= NULL){
            temp1=temp;
            temp= temp->next;
        }
        temp1->next=NULL;
        delete temp;
        print();
    }
    else if(head->next== NULL){
        temp= head;
        delete temp;
        cout<<"List is Empty";
    }
}

void print(){
    node *temp;
    temp=head;

    cout<<"Linked List:";
    while(temp!=NULL){
        cout<<"->"<<temp->data;
        temp= temp->next;
    }
    cout<<endl;
}