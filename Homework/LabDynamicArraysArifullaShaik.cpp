/*
    Assignment: Dynamic Arrays
    Name: Arifulla Shaik
    ID: 1159141
    Date: 1/25/2020
*/

#include <iostream>
using namespace std;

int main(){
    int arraySize, userInput, i = 0;
    cout << "Enter the lenth of the array: ";
    cin >> arraySize;

    int *dynamicArray = new int[arraySize];

    while(i != arraySize){
        cout << "Enter a number: ";
        cin >> userInput;

        if(userInput == -1){
            for(int j=i; j<arraySize-i; j++){
                dynamicArray[j] = 0;
            }
            break;
        }

        dynamicArray[i] = userInput;
        i++;
    }

    cout << "[";
    for(int i=0; i<arraySize; i++){
        if(i == arraySize-1){
            cout << dynamicArray[i];
        }else{
            cout << dynamicArray[i] << ", ";
        }
    }
    cout << "]";

    delete[] dynamicArray;
}

/*
    Program Output:

        Enter the lenth of the array: 5
        Enter a number: 1
        Enter a number: 2
        Enter a number: 3
        Enter a number: 4
        Enter a number: 5
        [1, 2, 3, 4, 5]

        Enter the lenth of the array: 5
        Enter a number: 1
        Enter a number: 2
        Enter a number: -1
        [1, 2, 0, 0, 0]
*/

