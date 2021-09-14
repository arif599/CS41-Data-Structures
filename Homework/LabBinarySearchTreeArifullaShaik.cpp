/*
    Assignment: Binary Search Tree
    Name: Arifulla Shaik
    ID: 1159141
    Date: 3/2/2020
*/

#include <iostream>
using namespace std;

class node
{  
    public:
        int data;
        node* left;
        node* right;
};

class BST{
    public:
        node* root;
    
    public:
        BST(){
            root = NULL;  
        }

        void add(int input){
            node* tree = new node;
            node* parent;

            tree->data = input;
            tree->left = NULL;
            tree->right = NULL;
            parent = NULL;

            if(root == NULL){
                root = tree;
            }
            else{
                node* currentNode = root;
                while(currentNode != NULL){
                    parent = currentNode;
                    if(tree->data > currentNode->data){
                        currentNode = currentNode->right;
                    }else{
                        currentNode = currentNode->left;
                    }
                }

                if(tree->data < parent->data){
                    parent->left = tree;
                }else{
                    parent->right = tree;
                }
            }
        }

        void print(node* n){
            if(n != NULL){
                if(n->left){
                    print(n->left);
                }
                cout << n->data << " ";
                if(n->right){
                    print(n->right);
                }
            }
        }

};

int main()
{
	BST tree;
	int sizeInput;
    int dataInput;

	cout << "Enter size of numbers to input: ";
	cin >> sizeInput;
	for (int i = 1;i <= sizeInput; i++)
	{
		cout << "Number "<< i << ": ";
		cin >> dataInput;
		tree.add(dataInput);
	}
	cout << "Print: ";
    tree.print(tree.root);
}

/*
Output:
    Enter size of numbers to input: 5
    Number 1: 16
    Number 2: 5
    Number 3: 23
    Number 4: 50
    Number 5: 8
    Print: 5 8 16 23 50
*/