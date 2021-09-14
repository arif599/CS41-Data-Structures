/*
    Assignment: Binary Tree Lab
    Name: Arifulla Shaik
    ID: 1159141
    Date: 2/23/2020
*/

#include<iostream>
using namespace std;

class binaryTree{
    private:
        int data[5];
        int count;
    public:
        binaryTree(){
            for(int i = 0; i < 5; i++){
                data[i] = -1;
            }
            count = 0;
        }

        int add(int n){
            if(count == 5){
                cout << "ERROR: ARRAY OUT OF BOUNDS" << endl;
                return -1;
            }

            data[count] = n;
            count++;
        }

        void preOrder(int n){
            if(n < (5 *  2) / 2){
                cout << data[n] << " ";
                preOrder(n*2 + 1);
                preOrder(n*2 + 2);
            }
        }
};

int main(){
    binaryTree tree;
    tree.add(1);
    tree.add(2);
    tree.add(3);
    tree.add(4);
    tree.add(5);
    tree.preOrder(0);
}
