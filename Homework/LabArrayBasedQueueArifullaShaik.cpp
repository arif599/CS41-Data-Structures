/*
    Assignment: Array Based Queue
    Name: Arifulla Shaik
    ID: 1159141
    Date: 1/26/2020
*/

#include <iostream>
using namespace std;

class ArrayQueue{
    public:
        const int MAXSIZE = 10;
        int array[10] = {0};
        int count = 0;
        int front = -1;
        int back = -1;

        void enqueue(int num);
        int dequeue();
        bool isEmpty();
};
bool ArrayQueue::isEmpty(){
    if(front == -1 && back == -1){
        return true;
    }else{
        return false;
    }
}
void ArrayQueue::enqueue(int num){
    if(back == MAXSIZE-1){
        cout << "ERROR: queue is full!" << endl;
    }else{

        if(front == -1){
            front = 0;
        }
        array[count] = num;
        count++;
        back++;
    }
}
int ArrayQueue::dequeue(){
    if(isEmpty()){
        cout << "ERROR: queue is empty" << endl;
        return -1;
    }else if(back == front){
        back = -1;
        front = -1;
        return -1;
    }else{
        return array[front++];
    }
}

int main(){
    ArrayQueue queue;
    queue.enqueue(10);
    queue.enqueue(5);
    cout << "Pop: " << queue.dequeue() << endl;
    queue.enqueue(17);
    queue.enqueue(6);

    cout << "Front pointer: " << queue.front << endl;
    cout << "Back pointer: " << queue.back << endl;
    cout << "Elements in Stack: ";
    cout << "[";
    for(int i=0; i<10; i++){
        if(i == 9){
            cout << queue.array[i];
        }else{
            cout << queue.array[i] << ", ";
        }
    }
    cout << "]";
}

/*
    Program Output:

        Pop: 1
        Pop: 2
        Front pointer: 2
        Back pointer: 4
        Elements in Stack: [1, 2, 7, 8, 9, 0, 0, 0, 0, 0]
*/
