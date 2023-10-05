// recursion
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void reverse(Node *&head, Node *curr, Node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    Node *forward = curr->next;
    reverse(head, forward, curr);

    curr->next = prev;
}
Node *reverselinkedlist(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *curr = head;
    Node *prev = NULL;
    reverse(head, curr, prev);
    return head;
}

int main(int argc, char const *argv[])
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    reverselinkedlist(head);

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}
