#include <iostream>
using namespace std;

void insert();
void print();

struct node{
    int data;
    node *next;
};
node *head=NULL;

int main(){
    int choice;
    do{
        cout<<endl<<"*************************"<<endl;
        cout<<"1- Insert"<<endl;
        cout<<"2- Print"<<endl;
        cout<<"3- Exit"<<endl;
        cout<<"*************************"<<endl;
        
        cout<<"Enter: ";
        cin>>choice;

        switch(choice){
            case 1: insert(); break;
            case 2: print(); break;
            default: break;
        }
    }while(choice<3);
    return 0;
}

void insert(){
    int number1,number2;
    cout<<"Enter a number: ";
    cin>>number1;
    cout<<"Where to insert: ";
    cin>>number2;

    node *newnode;
    newnode=new node;
    newnode->data=number1;
    newnode->next=NULL;

    if(head==NULL){
        head=newnode;
    }

    else{
        node *temp;
        temp=head;
        for(int i=1;i<=number2-2;i++){
            temp= temp->next;
        }
        newnode->next= temp->next;
        temp->next= newnode;
    }
    print();
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