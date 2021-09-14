/*
    Assignment: Simple Array
    Name: Arifulla Shaik
    ID: 1159141
    Date: 1/25/2020
*/

#include <iostream>
using namespace std;

int main(){
    int simpleArray[5];
    int userInput;

    for(int i=0; i<5; i++){
        cout << "Enter a integer: ";
        cin >> userInput;
        simpleArray[i] = userInput;
    }

    cout << "[";
    for(int i=0; i<5; i++){
        if(i == 4){
            cout << simpleArray[i];
        }else{
            cout << simpleArray[i] << ", ";
        }
    }
    cout << "]";
}

/*
    Program Output:

    Enter a integer: 1
    Enter a integer: 2
    Enter a integer: 3
    Enter a integer: 4
    Enter a integer: 5
    [1, 2, 3, 4, 5]
*/

