/*
    Assignment: Program 4
    Name: Arifulla Shaik
    ID: 1159141
    Date: 5/19/2021
*/


#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<math.h>

#define TABLESIZE 100
using namespace std;

// class for Node
class Node{
    public:
        // instance variabels for Node
        int data;
        int scope;
        char varName[1000];
        Node* next;
};

// class for HashTable
class HashTable{
    public:
        // instance variabels for HashTable
        Node* arr[TABLESIZE];
    public:
        // initalizes the arr for the hash table with null at each index
        HashTable(){
            for(int i = 0; i < TABLESIZE; i++){
                arr[i] = NULL;
            }
        }

        // Program character based folding implementation
        int Hash(char* data){
            int size = strlen(data);
            int val = 0;

            for(int i = 0; i < size; i++){
                val += data[i] * i;
            }

            return val % TABLESIZE;
        }

        //function that inserts a Node into the hash table 
        void insertNode(char* newVarName, char* newData, int newScope){
            int index = Hash(newVarName);
            Node* temp = new Node;
            strcpy(temp->varName, newVarName);
            temp->data = atoi(newData);
            temp->scope = newScope;
            temp->next = NULL;

            if(arr[index] == NULL){
                arr[index] = temp;
            }else{
                Node* currNode = arr[index];
                while(currNode->next != NULL){
                    currNode = currNode->next;
                }
                currNode->next = temp;
            }
        }

        // searches for the node based on the varName and scope
        Node* search(char* varName, int scope){
            int index = Hash(varName);
            Node* currNode = arr[index];

            if(currNode == NULL){
                cout << varName << " IS UNDEFINED" << endl;
                return NULL;
            }else{
                while((currNode->next != NULL) && (strcmp(currNode->varName, varName) != 0)){
                    currNode = currNode->next;
                }
        
                if((scope >= currNode->scope) && (strcmp(currNode->varName, varName) == 0)){
                    return currNode;
                }else if(currNode->next == NULL){
                    cout << varName << " IS UNDEFINED" << endl;
                    return NULL;
                }
                else{
                    return NULL;
                }
            }

        }
        
        // this function does the calculation and outputs to the screen the results
        void calculating(char* varName, char* operation, char* operand, int commandCount, int scope){
            Node* currNode = search(varName, scope);
            if(currNode != NULL){
                if(commandCount == 1){
                    cout << varName << " IS " << currNode->data << endl;
                }else{
                    int calculation = 0;
                    int intOperand = atoi(operand);

                    if(strcmp(operation, "+") == 0){
                        calculation = currNode->data + intOperand; 
                    }else if(strcmp(operation, "-") == 0){
                        calculation = currNode->data - intOperand; 
                    }
                    else if(strcmp(operation, "/") == 0){
                        calculation = currNode->data / intOperand; 
                    }
                    else if(strcmp(operation, "*") == 0){
                        calculation = currNode->data * intOperand; 
                    }
                    else if(strcmp(operation, "%") == 0){
                        calculation = currNode->data % intOperand; 
                    }
                    else if(strcmp(operation, "^") == 0){
                        calculation = (int)pow(currNode->data,intOperand);
                    }

                    cout << varName << " " << operation << " " << operand << " IS " << calculation << endl; 
                }
            }
        }
};


// driver code
int main(){
    HashTable table; 
	string readLine;
	char* title;
	char tempStorage[1000];
	int scope = 0;
	int commandCount;

    // file location
	ifstream myFile("C:\\Users\\arifu\\Desktop\\CS41 HW\\Project 4\\input.txt", ios::in);

    // extracting contents from files and populating HashTable object
	if(myFile.is_open()){
		while (getline(myFile, readLine)){
			strcpy(tempStorage, readLine.c_str());
			title = strtok(tempStorage, " ");

			if(strcmp(title, "START") == 0){
                scope++;
            }else if(strcmp(title, "FINISH") == 0){
                scope--;
            }else if(strcmp(title, "COM") == 0){
                NULL;
            }else if(strcmp(title, "PRINT") == 0){
				char* varName = strtok(NULL, " ");
				char* operation = strtok(NULL, " ");
				char* operand = strtok(NULL, " ");

				if(operation == NULL){
                    commandCount = 1;
                }else{
                    commandCount = 3;
                }
				table.calculating(varName, operation, operand, commandCount, scope);
			}else if(strcmp(title, "VAR") == 0){
				char* varName = strtok(NULL, " ");
				char* data = strtok(NULL, "=");
				table.insertNode(varName, data, scope);
			}else{
		    	Node* currNode = table.search(title, scope);
				char* specialOperator = strtok(NULL, " ");

				if(strcmp(specialOperator, "++") == 0){
                    currNode->data = currNode->data + 1;
                }
				else if(strcmp(specialOperator, "--") == 0){
                    currNode->data = currNode->data - 1;
                }
				else if(strcmp(specialOperator, "=") == 0){
					char* data = strtok(NULL, " ");
					if(currNode != NULL){
                        currNode->data = atoi(data);
                    }
				}
				else{
                    cout << "ERROR: UNRECOGNIZED OPERATOR" << endl;
                }	
			}
		}
	}
}

/*
    SAMPLE OUTPUT:
        BORAMIR IS 25
        LEGOLAS IS 101
        GANDALF IS UNDEFINED
        BORAMIR * 2 IS 52
        GANDALF IS 49
        BORAMIR IS 26
        GANDALF IS UNDEFINED
        LEGOLAS IS 1000
        LEGOLAS IS 1000
        LEGOLAS IS 999

    SAMPLE INPUT:
        START
        VAR BORAMIR = 25
        VAR LEGOLAS = 101
        PRINT BORAMIR
        BORAMIR ++
        PRINT LEGOLAS
        PRINT GANDALF
        PRINT BORAMIR * 2
        COM
        COM NESTED BLOCK
        COM
        START
        VAR GANDALF = 49
        PRINT GANDALF
        PRINT BORAMIR
        FINISH
        PRINT GANDALF
        START
        LEGOLAS = 1000
        PRINT LEGOLAS
        FINISH
        PRINT LEGOLAS
        LEGOLAS --
        PRINT LEGOLAS
        FINISH
*/