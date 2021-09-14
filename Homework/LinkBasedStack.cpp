/*
    Assignment: Link Based Stack
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

class LinkStack{
    public:
        Node* top = NULL;
        int count;

    public:
        // Accepts a number and adds to the end of the stack
        void push(int num){
            // Scenario 1: the link list is empty
            if(isEmpty()){
                // create a new node
                Node* newNode = new Node();
                newNode->data = num;
                newNode->next = top;

                // set the top pointer
                top = newNode;
                count++;
            }else{
                // Scenario 2: the link list is not empty
                // create a new node
                Node* newNode = new Node();
                newNode->data = num;
                newNode->next = top;
                // move back pointer
                top = newNode;
                count++;
            }
        }

        // Returns a number from the top of the stack
        int pop(){
            // Scenario 1: link list is empty
            if(isEmpty()){
                // emitting an error
                cout << "ERROR: no elements in the stack" << endl;
                return -1;
            }else{
                // Secenario 2: link list is not empty
                int prevTopData = top->data;
                Node* prevTop = top;
                top = top->next;
                delete(prevTop);
                return prevTopData;
            }
        }
        
        // prints the contents of the queue
        void print(){
            Node* currentNode = top;
            int i = 0;
            while(currentNode != NULL){
                cout << "\tNode " << i << ": " << currentNode->data << endl;
                currentNode = currentNode->next;
                i++;
            }
        }

        // checks if the top pointer is NULL
        bool isEmpty(){
            return top == NULL;
        }
        
};

int main(){
    LinkStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    cout << "Pop: " << stack.pop() << endl;
    cout << "Pop: " << stack.pop() << endl;

    cout << "Elements in Stack: " << endl;
    stack.print();
}

/*
    Program Output:
        Pop: 9
        Pop: 8
        Elements in Stack:
                Node 0: 7
                Node 1: 2
                Node 2: 1

*/

