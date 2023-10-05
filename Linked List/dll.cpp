#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << val << endl;
    }
};

// traversing a linked list

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

// gives length of linked list
int getlength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// insertion at head
void insertathead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {

        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// insertion at tail
void insertattail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// insertion at position
void insertatposition(Node *&head, Node *&tail, int position, int d)
{
    // insert at head
    if (position == 1)
    {
        insertathead(head, tail, d);
        return;
    }

    // to go to the position
    Node *temp = head;
    int c = 1;
    while (c < position - 1)
    {
        temp = temp->next;
        c++;
    }

    // insert at last
    if (temp->next == NULL)
    {
        insertattail(head, tail, d);
        return;
    }
    // to add somewhere in middle
    Node *nodetoinsert = new Node(d);

    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}

void deleteNode(int position, Node *&head)
{
    // deleting first node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // middle or last
        Node *curr = head;
        Node *prev = NULL;
        int c = 1;
        while (c < position)
        {
            prev = curr;
            curr = curr->next;
            c++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    print(head);
    cout << getlength(head) << endl;
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    cout << endl;

    insertathead(head, tail, 11);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    cout << endl;

    insertathead(head, tail, 10);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    cout << endl;

    insertathead(head, tail, 9);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    cout << endl;

    insertattail(head, tail, 13);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    cout << endl;

    insertatposition(head, tail, 2, 100);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    cout << endl;

    deleteNode(2, head);
    print(head);

    deleteNode(3, head);
    print(head);

    return 0;
}