/*
    Assignment: Sort
    Name: Arifulla Shaik
    ID: 1159141
    Date: 2/4/2020
*/

#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 6;
    int arr[SIZE] = {4, 2, 1, 6, 5, 3};

    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // printing the elements in the array
    cout << "Array: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
}

/*
    Program Output:
        Array: 1, 2, 3, 4, 5, 6

*/
