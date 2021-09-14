/*
    Assignment: Program 1
    Name: Arifulla Shaik
    ID: 1159141
    Date: 2/13/2020
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Node{
    public:
        float data;
        Node* next;
};

class LinkStack{
    public:
        Node* top = NULL;
        int count = 0;

    public:
        // Accepts a number and adds to the end of the stack
        void push(float num){
            // create a new node
            Node* newNode = new Node();
            newNode->data = num;
            newNode->next = top;

            // set the top pointer
            top = newNode;
            count++;
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
                Node* prevTop = top;
                int prevTopData = top->data;
                top = top->next;
                delete(prevTop);
                count--;
                return prevTopData;
            }
        }
        
        // adds the top two values of the stack
        void add(){
            if(count == 1){
                throw "ERROR: Too Many Operators!";
            }

            float result = top->next->data + top->data;
            pop();
            top->data = result;
            print();
        }

        // subtracts the top two values of the stack
        void subtract(){
            if(count == 1){
                throw "ERROR: Too Many Operators!";
            }

            float result = top->next->data - top->data;
            pop();
            top->data = result;
            print();
        }

        // multiplies the top two values of the stack
        void multiply(){
            if(count == 1){
                throw "ERROR: Too Many Operators!";
            }

            float result = top->next->data * top->data;
            pop();
            top->data = result;
            print();
        }

        // divides the top two values of the stack
        void divide(){
            if(top->data == 0){
                throw "ERROR: Division By Zero!";
            }

            if(count == 1){
                throw "ERROR: Too Many Operators!";
            }

            float result = top->next->data / top->data;
            pop();
            top->data = result;
            print();
            
        }

        // prints the contents of the stack
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
    string userInput;
    cout << "Expression: ";
    getline(cin, userInput);
    // cout << "\n" << "Output: " << endl;
    
    while(stof(userInput) != 0){
        LinkStack stack;
        string *userInputCopy = &userInput;
        string tempUserInput;
        char delimiter = ' ';
        bool errorFound = false;

        stringstream strString(userInput);
        while(getline(strString, tempUserInput, delimiter)){
            float number;
            
            try{
                number = stof(tempUserInput);
            }catch(invalid_argument){
                try{
                    // checking what operator was selected
                    if(tempUserInput == "+"){
                        stack.add();
                        continue;
                    }
                    if(tempUserInput == "-"){
                        stack.subtract();
                        continue;
                    }
                    if(tempUserInput == "*"){
                        stack.multiply();
                        continue;
                    }
                    if(tempUserInput == "/"){
                        stack.divide();
                        continue;
                    }
                }catch(const char *errorMsg){
                    // any errors caught here
                    cout << errorMsg << endl;
                    cout << endl;
                    errorFound = true;
                    break;
                }
                cout << "ERROR: Invalid input!" << endl;
                cout << endl;
                break;
            }

            stack.push(number);
        }

        // too many operands error
        if(errorFound == false && stack.count != 1){
            cout << "ERROR: Too Many Operands!" << endl;

            cout << "Top of stack: " << stack.top->data << endl;
            Node *currentNode = stack.top;
            while(currentNode != NULL){
                cout << currentNode->data << "-->";
                currentNode = currentNode->next;
            }
            cout << "Bottom of stack: " << currentNode->data << endl;

            cout << endl;
            errorFound = true;
        }

        // if no error, print the results
        if(errorFound == false){
            cout << "Result: " << *userInputCopy << " = " << stack.top->data << endl;
            cout << endl;
        }

        // delete the stack and variables
        delete &stack;
        delete userInputCopy;
        delete &tempUserInput;
        delete &delimiter;
        delete &errorFound;

        // prompt the user again
        cout << "Expression: ";
        getline(cin, userInput);
    }
}

/*
    Program Output:
        Expression: 10 15 +
        Result: 10 15 + = 25

        Expression: 10 15 -
        Result: 10 15 - = -5

        Expression: 2.5 3.5 +
        Result: 2.5 3.5 + = 6

        Expression: 10 0 /
        ERROR: Division By Zero!

        Expression: 10 20 * /
        ERROR: Too Many Operators!

        Expression: 12 20 30 /
        ERROR: Too Many Operands!

        Expression: 100 12 50 25 / * - -2 /
        Result: 100 10 50 25 / * - -2 / = -40

        Expression: 1 2 3 + +
        Result: 1 2 3 + + = 6

        Expression: 1 2 -
        Result: 1 2 - = -1

        Expression: 1 2 + 3 - 4 * 5 6 - -
        Result: 1 2 + 3 - 4 * 5 6 - - = 1

*/

