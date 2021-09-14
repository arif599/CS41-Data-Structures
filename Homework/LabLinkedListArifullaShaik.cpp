/*
    Assignment: Linked List
    Name: Arifulla Shaik
    ID: 1159141
    Date: 1/28/2020
*/

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
    public:
        Node* head;
    
    public:
        LinkedList(){
            head = nullptr;
        }
        
        void add(int num){
            // Node* prevHead = head;
            // head = new Node;
            // head->next = prevHead;
            // head->data = num;

            Node* newNode = new Node();
            newNode->data = num;
            newNode->next = head;
            head = newNode;

        }

        void print(){
            Node* itrNode = head;
            while(itrNode != nullptr){
                cout << itrNode->data << endl;
                itrNode = itrNode->next;
            }
        }
};

int main(){
    LinkedList ll;
    int userInput;

    while(userInput != -1){
        cout << "Enter: ";
        cin >> userInput;
        ll.add(userInput);
    }

    ll.print();
}
/*
    Program Output:
    
        Enter: 1
        Enter: 2
        Enter: 3
        Enter: 4
        Enter: 5
        Enter: -1
        -1
        5
        4
        3
        2
        1
       
*/
