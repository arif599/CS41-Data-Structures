#include <iostream>
using namespace std;

int main(){
    cout << "-------------ROW MAJOR CALCULATOR--------------" << endl;
    int userInput;

    do{
        int baseAddress, elementSize, rows, columns = 0;
        int givenRow, givenColumn = 0;
        userInput = 1;
        
        cout << "Base Address: ";
        cin >> baseAddress;
        cout << "Rows in the array: ";
        cin >> rows;
        cout << "Columns in the array: ";
        cin >> columns;
        cout << "Element size: ";
        cin >> elementSize;
        cout << endl;
        

        while(userInput == 1){
            cout << "Enter the ROW and COLUMN of the element you are trying to find" << endl;
            cout << "Row: ";
            cin >> givenRow;
            cout << "Column: ";
            cin >> givenColumn;

            int result = baseAddress + (givenRow*columns*elementSize) + (givenColumn*elementSize);
            cout << "----------------------------------------------------------------" << endl;
            cout << "Memory address of Array[" << givenRow << "][" << givenColumn << "] is " << result << endl;
            cout << "----------------------------------------------------------------" << endl;
            cout << endl;
            

            cout << "1) New Entry (same info but different row & column)" << endl;
            cout << "2) Reset" << endl;
            cout << "3) Exit" << endl;
            cout << "Enter: ";
            cin >> userInput;
            cout << endl;
        }
    }while(userInput != 3);
}