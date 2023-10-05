#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data" << value << endl;
    }
};

void insertnode(Node *&tail, int element, int d)
{
    // assuming that element is present in list

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // not empty list
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // element found and curr on that element
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node *&tail, int value)
{
    // empty list
    if (tail == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        // non empty
        // assuming that value is present
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if (curr == prev)
        {
            tail = NULL;
        }
        if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *tail)
{
    Node *temp = tail;
    if(tail == NULL){
        cout<<"List is empty";
        return;
    }
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
    ;
}

int main(int argc, char const *argv[])
{
    Node *tail = NULL;

    insertnode(tail, 5, 3);
    print(tail);

    insertnode(tail, 3, 5);
    print(tail);

    insertnode(tail, 5, 7);
    print(tail);

    insertnode(tail, 7, 9);
    print(tail);

    insertnode(tail, 5, 6);
    print(tail);

    insertnode(tail, 9, 10);
    print(tail);

    insertnode(tail, 5, 0);
    print(tail);

    deleteNode(tail, 3);
    print(tail);
    deleteNode(tail, 5);
    print(tail);

    return 0;
}