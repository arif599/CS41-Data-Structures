/*
    Assignment: Lab Loop - Recursion
    Name: Arifulla Shaik
    ID: 1159141
    Date: 2/10/2020
*/

#include <iostream>
using namespace std;

int sum(int num){

    if(num < 1){
        return 0;
    }

    int result = 0;
    for(int i=1; i<=num; i++){
        result += i;
    }
    return result;
}

int main(){
    cout << sum(5) << endl;
}

/*
    Program Output:

        15

*/

