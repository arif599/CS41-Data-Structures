/*
    Assignment: Array Based Stack
    Name: Arifulla Shaik
    ID: 1159141
    Date: 1/26/2020
*/

#include <iostream>
using namespace std;

class ArrayStack{
    public:
        const int MAXSIZE = 10;
        int array[10] = {0};
        int count = 0;

        void push(int num);
        int pop();
        bool isEmpty();
};
bool ArrayStack::isEmpty(){
    if(count == 0){
        return true;
    }else{
        return false;
    }
}
void ArrayStack::push(int num){
    if(count < MAXSIZE){
        array[count] = num;
        count++;
    }else{
        cout << "ERROR: the stack is full!" << endl;
    }
}
int ArrayStack::pop(){
    if(isEmpty() != true){
        int temp = array[count-1];
        array[count-1] = 0;
        count--;
        return temp;
    }else{
        cout << "ERROR: the stack is empty!" << endl;
        return -1;
    }
}

int main(){
    ArrayStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
 
    cout << "Pop: " << stack.pop() << endl;
    
    stack.push(7);
    stack.push(8);
    stack.push(9);


    cout << "Elements in Stack:" << endl;
    for(int i=0; i<10; i++){
        cout << stack.array[i] << endl;
    }
}

/*
    Program output:
        Pop: 6
        Elements in Stack:
        1
        2
        3
        4
        5
        7
        8
        9
        0
        0
*/
