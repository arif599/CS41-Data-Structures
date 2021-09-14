/*
    Assignment: Link Based Queue
    Name: Arifulla Shaik
    ID: 1159141
    Date: 2/2/2020
*/

#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class LinkQueue{
    public:
        Node* front = NULL;
        Node* back = NULL;
        int count;

    public:
        // Accepts a number and adds to the end of the queue
        void enqueue(int num){
            // Scenario 1: the link list is empty
            if(isEmpty()){
                // create a new node
                Node* newNode = new Node();
                newNode->data = num;
                newNode->next = NULL;

                // set the front and back pointers
                front = newNode;
                back = newNode;
                count++;
            }else{
                // Scenario 2: the link list is not empty
                // create a new node
                Node* newNode = new Node();
                newNode->data = num;
                newNode->next = NULL;

                // add the new node to back
                back->next = newNode;
                // move back pointer
                back = newNode;
                count++;
            }
        }

        // Returns a number from the front of the queue
        int dequeue(){
            // Scenario 1: link list is empty
            if(isEmpty()){
                // emitting an error
                cout << "ERROR: no elements in the queue" << endl;
                return -1;
            }else{
                // Secenario 2: link list is not empty
                Node *temp = front;

                int prevHeadData = front->data;

                front = front->next;

                    delete temp;

                    return prevHeadData;
            }
        }
        
        // prints the contents of the queue
        void print(){
            Node* currentNode = front;
            int i = 0;
            while(currentNode != NULL){
                cout << "\tNode " << i << ": " << currentNode->data << endl;
                currentNode = currentNode->next;
                i++;
            }
        }

        // checks if the front and back pointer is NULL
        bool isEmpty(){
            return front == NULL;
        }
        
};

int main(){
    LinkQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);
    cout << "Pop: " << queue.dequeue() << endl;
    cout << "Pop: " << queue.dequeue() << endl;

    cout << "Front pointer: " << queue.front << endl;
    cout << "Back pointer: " << queue.back << endl;
    cout << "Elements in Queue: " << endl;
    queue.print();
}

/*
    Program Output:

        Pop: 1
        Pop: 2
        Front pointer: 0xfe6f38
        Back pointer: 0xfe6f58
        Elements in Queue:
                Node 0: 7
                Node 1: 8
                Node 2: 9

*/

