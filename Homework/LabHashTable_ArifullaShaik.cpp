/*
    Assignment: Hash Table
    Name: Arifulla Shaik
    ID: 1159141
    Date: 4/5/2020
*/

#include<iostream>
using namespace std;

class HashTable{
    public:
	    int arr[27];

    public:
        HashTable(){
            for(int i = 0; i < 27; i++){
                arr[i] = -1;
            }   
        }

        int Hash(int data){
            int hashCode = data % 27;
            return hashCode;
        }

        bool add(int data){
            int index = Hash(data);
            if(arr[index] == -1){
                arr[index] = data;
                cout << "Inserted " << data << endl;
                return true;
            }else{
                linearProbe(data);
            }
        }

        bool linearProbe(int data){
            int index = Hash(data);
            int probe = Hash(data + 1);

            while(index != probe){
                if(arr[probe] == -1){
                    arr[probe] = data;
                    cout << "Inserted " << data << endl;
                    return true;
                }
                probe = Hash(++probe);
            }
            cout << "Error cannot inserte " << data << endl;
            return false;
        }

        int lookup(int data){
            int index = Hash(data);

            if(arr[index] == data){
                cout << "Found at index: " << index << endl;
                return index;
            }

            int nextIndex = Hash(index+1);
            while(arr[nextIndex] != -1 && index != nextIndex){
                if(arr[nextIndex] == data){
                    cout << "Found at index: " << index << endl;
                    return nextIndex;
                }
                nextIndex = Hash(nextIndex+1);
            }

            cout << "NOT FOUND" << endl;
            return -1;
        }
};



int main(){

	HashTable table;
    
    table.add(0);
    table.add(5);
    table.add(10);
    table.add(15);
    table.add(20);
    table.add(25);
    table.add(30);
    table.add(30);

    table.lookup(10);
	table.lookup(1000);
	table.lookup(5);
}


/*
SAMPLE OUTPUT:
    Inserted 0        
    Inserted 5        
    Inserted 10       
    Inserted 15       
    Inserted 20       
    Inserted 25       
    Inserted 30       
    Inserted 30       
    Found at index: 10
    NOT FOUND
    Found at index: 5
*/