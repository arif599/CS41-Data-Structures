/*
    Assignment: Program 2
    Name: Arifulla Shaik
    ID: 1159141
    Date: 3/17/2020
*/

#include <iostream>
#include <string>
using namespace std;

// Node class for the doubly linked list
class Node{
    public:
        Node *prev;
        int weight;
        string name;
        Node *next;
};

// class for doubly linked list
class DoublyLinkedList{
    public:
        Node *weightHead;
        Node *nameHead;

    public:
        // constructor that initializes instance vars to NULL
        DoublyLinkedList(){
            weightHead = NULL;
            nameHead = NULL;
        }

        // returns if head of weight is pointing to NULL
        bool isWeightEmpty(){
            return weightHead == NULL;
        }

        // returns if head of name is pointing to NULL
        bool isNameEmpty(){
            return nameHead == NULL;
        }

        // inserting a new node based on weight
        void insertByWeight(int weight, string name){
            Node *newNode = new Node();
            newNode->weight = weight;
            newNode->name = name;
            
            // if empty then new node becomes head
            if(isWeightEmpty()){
                newNode->prev = NULL;
                newNode->next = NULL;
                weightHead = newNode;
            }
            // checks if the weight is less than the head
            else if(weight <= weightHead->weight){
                newNode->next = weightHead;
                newNode->prev = NULL;
                weightHead = newNode;
            }
            // traverses the doubly linked list and insertes the new node in its right position
            else{
                Node *currentNode = weightHead;
                while(currentNode != NULL){
                    if(currentNode->next == NULL){
                        // insert new node at the tail
                        newNode->next = NULL;
                        newNode->prev = currentNode;
                        currentNode->next = newNode;
                        break;
                    }
                    if(currentNode->weight <= weight && weight <= currentNode->next->weight){
                        // insert new node between two nodes
                        newNode->prev = currentNode;
                        newNode->next = currentNode->next;
                        currentNode->next = newNode;
                        break;
                    }
                    currentNode = currentNode->next;
                }
            }
        }

        // inserting a new node based on name
        void insertByName(int weight, string name){
            Node *newNode = new Node();
            newNode->weight = weight;
            newNode->name = name;
            
            // if empty then new node becomes head
            if(isNameEmpty()){
                newNode->prev = NULL;
                newNode->next = NULL;
                nameHead = newNode;
            }
            // checks if the name is less than the head
            else if(name <= nameHead->name){
                newNode->next = nameHead;
                newNode->prev = NULL;
                nameHead = newNode;
            }
            // traverses the doubly linked list and insertes the new node in its right position
            else{
                Node *currentNode = nameHead;
                while(currentNode != NULL){
                    if(currentNode->next == NULL){
                        // insert new node at the tail
                        newNode->next = NULL;
                        newNode->prev = currentNode;
                        currentNode->next = newNode;
                        break;
                    }
                    if(currentNode->name <= name && name <= currentNode->next->name){
                        // insert new node between two nodes
                        newNode->prev = currentNode;
                        newNode->next = currentNode->next;
                        currentNode->next = newNode;
                        break;
                    }
                    currentNode = currentNode->next;
                }
            }
        }

        // prints the nodes in doubly linked list by acending order by weight
        void printByWeight(){
            cout << "Printing by weight: " << endl;
            Node *currentNode = weightHead;
            while(currentNode != NULL){
                cout << currentNode->name << " - " << currentNode->weight << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }

        // prints the nodes in doubly linked list by acending order by name
        void printByName(){
            cout << "Printing by name: " << endl;
            Node *currentNode = nameHead;
            while(currentNode != NULL){
                cout << currentNode->name << " - " << currentNode->weight << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }

};


int main(){
    DoublyLinkedList list;
    int userInputWeight;
    string userInputName;
 
	for (int i = 0; i < 15; i++){
		cout << "Enter Name #" << i + 1 << " : ";
		cin >> userInputName;
        cin.ignore();
		cout << "Enter Weight #" << i + 1 << " : ";
		cin >> userInputWeight;
		
		list.insertByWeight(userInputWeight,userInputName);
		list.insertByName(userInputWeight, userInputName);
	}

    cout << endl;
	list.printByWeight();
	list.printByName();
}

/*
    OUTPUT:
    
        Enter Name #1 : Mark
        Enter Weight #1 : 150
        Enter Name #2 : Tina 
        Enter Weight #2 : 115
        Enter Name #3 : Zach 
        Enter Weight #3 : 55 
        Enter Name #4 : Amy  
        Enter Weight #4 : 140
        Enter Name #5 : Steve
        Enter Weight #5 : 220
        Enter Name #6 : Brian
        Enter Weight #6 : 250
        Enter Name #7 : Liz   
        Enter Weight #7 : 125 
        Enter Name #8 : Brian 
        Enter Weight #8 : 220 
        Enter Name #9 : Laura 
        Enter Weight #9 : 115 
        Enter Name #10 : Alex 
        Enter Weight #10 : 175
        Enter Name #11 : Jason
        Enter Weight #11 : 210
        Enter Name #12 : Eric 
        Enter Weight #12 : 175
        Enter Name #13 : Aaron
        Enter Weight #13 : 195
        Enter Name #14 : Kim
        Enter Weight #14 : 135
        Enter Name #15 : Brandon
        Enter Weight #15 : 78

        Printing by weight:
        Zach - 55
        Brandon - 78
        Laura - 115
        Tina - 115
        Liz - 125
        Kim - 135
        Amy - 140
        Mark - 150
        Eric - 175
        Alex - 175
        Aaron - 195
        Jason - 210
        Brian - 220
        Steve - 220
        Brian - 250

        Printing by name:
        Aaron - 195
        Alex - 175
        Amy - 140
        Brandon - 78
        Brian - 220
        Brian - 250
        Eric - 175
        Jason - 210
        Kim - 135
        Laura - 115
        Liz - 125
        Mark - 150
        Steve - 220
        Tina - 115
        Zach - 55

*/