/*
    Assignment: IO
    Name: Arifulla Shaik
    ID: 1159141
    Date: 1/20/2020
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string userInput;
    string tempUserInput;
    char delimiter = ' ';

    cout << "Sentence: ";
    getline(cin,userInput);
    cout << "\n" << "Output: " << endl;
    
    stringstream strString(userInput);
    while(getline(strString, tempUserInput, delimiter)){
        float number;
        
        try{
            number = stof(tempUserInput);
        }catch(invalid_argument){
            cout << tempUserInput << endl;
            continue;
        }

        cout << 2*number << endl;
    }
}

/*
    Program Output:

        Sentence: Hello world, there are 3.5 items.

        Output:
        Hello
        world,
        there
        are
        7
        items.
*/