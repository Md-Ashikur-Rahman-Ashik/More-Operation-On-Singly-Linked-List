#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int integerValue;
    Node *nextPointer;

    Node(int integerValue)
    {
        this->integerValue = integerValue;
        this->nextPointer = NULL;
    }
};

void insertAtTail(Node *&head, Node *&tail, int integerValue)
{
    Node *newNode = new Node(integerValue);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->nextPointer = newNode;
        tail = newNode;
    }
}

void deleteAtAnyPosition(Node *&head, int desiredPosition)
{
    Node *deleteNode;
    Node *tmp = head;
    for (int i = 1; i < desiredPosition; i++)
    {
        tmp = tmp->nextPointer;
    }

    deleteNode = tmp->nextPointer;
    tmp->nextPointer = deleteNode->nextPointer;
    delete deleteNode;
}

void printLinkedList(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->integerValue << endl;
        tmp = tmp->nextPointer;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int inputValue;
    while (true)
    {
        cin >> inputValue;
        if (inputValue == -1)
        {
            break;
        }
        else
        {
            insertAtTail(head, tail, inputValue);
        }
    }

    int desiredPosition;
    cin >> desiredPosition;

    deleteAtAnyPosition(head, desiredPosition);
    printLinkedList(head);

    return 0;
}