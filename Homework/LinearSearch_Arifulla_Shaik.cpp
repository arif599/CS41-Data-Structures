/*
    Assignment: Linear Search
    Name: Arifulla Shaik
    ID: 1159141
    Date: 1/20/2020
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    int arr[10] = {5 , 14, 63, 2, 9, 41, 22, 75, 11, 58}; 
    bool found = false;
    int index;

    int userInput;
    cout << "Enter a number: ";
    cin >> userInput;

    for(int i=0; i<10; i++){
        if(userInput == arr[i]){
            found = true;
            index = i;
            break;
        }
    }

    if(found == true){
        cout << "Found at index " << index << endl;
        return index;
    }else{
        cout << "Not Found: -1" << endl;
        return -1;
    }
}

/*
    Program Output:

        Enter a number: 5
        Found at index 0

        Enter a number: 51
        Not Found -1
*/

