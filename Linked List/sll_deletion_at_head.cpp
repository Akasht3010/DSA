#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head;
void deletion_head()
{
    if (head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        node *temp = head;
        head = temp->next;
        delete temp;
    }
}

void insertion()
{
    if (head == NULL)
    {
        int x;
        cin >> x;
        node *element;
        element = new node;
        element->data = x;
        element->next = NULL;
        head = element;
    }
    else
    {
        int x;
        cin >> x;
        node *element;
        node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        
        element = new node;
        element->data = x;
        element->next = NULL;
        temp->next=element;
    }
    
}

int main(int argc, char const *argv[])
{
    int choice;
    cin>>choice;
    switch(choice):
    case 1:
        
    return 0;
}
