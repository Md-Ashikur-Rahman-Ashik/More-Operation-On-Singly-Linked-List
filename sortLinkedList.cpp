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

void sortLinkedList(Node *&head)
{
    Node *tmp = head;
    for (; tmp->nextPointer != NULL;)
    {
        Node *secondTmp = tmp->nextPointer;
        for (; secondTmp != NULL;)
        {
            if (tmp->integerValue < secondTmp->integerValue)
            {
                int swapValue = tmp->integerValue;
                tmp->integerValue = secondTmp->integerValue;
                secondTmp->integerValue = swapValue;
            }
            secondTmp = secondTmp->nextPointer;
        }
        tmp = tmp->nextPointer;
    }
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

    sortLinkedList(head);
    printLinkedList(head);

    return 0;
}