/*
    Assignment: Sorted Link list
    Name: Arifulla Shaik
    ID: 1159141
    Date: 2/4/2020
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head = NULL;

public:
    void add(int num)
    {
        if (isEmpty())
        {
            head = new Node();
            head->data = num;
            head->next = NULL;
        }
        else
        {
            Node *current = head;

            if (num < head->data)
            {
                // add infront of head
                Node *newNode = new Node();
                newNode->data = num;
                newNode->next = head;
                head = newNode;
            }
            else
            {
                while (current != NULL)
                {
                    if (current->next == NULL)
                    {
                        // adding new node to the end of the linked list
                        Node *newNode = new Node();
                        newNode->data = num;
                        newNode->next = NULL;
                        current->next = newNode;
                        break;
                    }
                    if (num > current->data && num < current->next->data)
                    {
                        // add new node in between two nodes
                        Node *newNode = new Node();
                        newNode->data = num;
                        newNode->next = current->next;
                        current->next = newNode;

                        // break after inserting element
                        break;
                    }
                    current = current->next;
                }
            }
        }
    }

    void print()
    {
        Node *current = head;

        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }

    bool isEmpty()
    {
        return head == NULL;
    }
};

int main()
{
    LinkedList list;
    int userInput;

    while (true)
    {
        cout << "Enter a number: ";
        cin >> userInput;

        if (userInput == -1)
        {
            break;
        }

        list.add(userInput);
    }

    list.print();
}

/*
    Program Output:
    
        Enter a number: 3
        Enter a number: 2
        Enter a number: 4
        Enter a number: 1
        Enter a number: 6
        Enter a number: -1
        1 2 3 4 6

        Enter a number: 3
        Enter a number: 5
        Enter a number: 9
        Enter a number: 6
        Enter a number: -1
        3 5 6 9
*/