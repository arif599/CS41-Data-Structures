/*
    Assignment: Program 3
    Name: Arifulla Shaik
    ID: 1159141
    Date: 4/1/2021
*/

#include <iostream>
#include <string>
using namespace std;

// Node class that is used to store data 
class Node{
    public:
        string name;
        int weight;
        Node *left;
        Node *right;

    public:
        // Node class constructor
        Node(string name, int weight){
            this->name = name;
            this->weight = weight;
            left = right = NULL;
        }
};

// inserts a node by alphabetical order
Node* insert(Node *root, string name, int weight, int count){
    // checks to see if count is equal to greater the 15 and if so then it will exit
    if (count >= 15){
        return NULL;
    }else{
        // using temp node and path node to determine where the new node will be placed
        Node *temp = new Node(name, weight);
        Node *currentNode = root;
        Node *path = NULL;

        // traversing the tree
        while(currentNode != NULL){
            path = currentNode;
            if(temp->name > currentNode->name){
                currentNode = currentNode->right;
            }
            else{
                currentNode = currentNode->left;
            }   
        }

        if(path == NULL){
            path = temp;
        }
        else if(temp->name > path->name){
            path->right = temp;
        }
        else{
            path->left = temp;
        }

        return path;
    }
}

// preorder traversal and prints name and weight
void preorder(Node* node){
    if (node == NULL){
        return;
    }
    else{
        cout << "\tName: " << node->name;
        cout << "\tWeight: " << node->weight << endl;
        preorder(node->left);
        preorder(node->right);
    }
}

// inorder traversal and prints name and weight
void inorder(Node* node){
    if (node == NULL){
        return;
    }
    else{
        inorder(node->left);
        cout << "\tName: " << node->name;
        cout << "\tWeight: " << node->weight << endl;
        inorder(node->right);
    }
}

// postorder traversal and prints name and weight
void postorder(Node* node){
    if (node == NULL){
        return;
    }
    else{
        postorder(node->left);
        postorder(node->right);
        cout << "\tName: " << node->name;
        cout << "\tWeight: " << node->weight << endl;
    }
}

// finds the height of a tree recursively 
int getHeight(Node* root){
    if (root == NULL){
        return 0;
    }else{
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if(leftHeight > rightHeight){
            return leftHeight+1;
        }else{
            return rightHeight+1;
        }
    }
}

// finds the total leaves within a tree and returns that value
int getTotalLeaves(Node *root){
    if (root == NULL){
        return 0;
    }
    else if(root->left == NULL && root->right == NULL){
        return 1;
    }
    else{
        return getTotalLeaves(root->left) + getTotalLeaves(root->right);
    }
}

// finds the first name in alphabetical order by traversing to the left side of the tree
string getMinName(Node *root){
    Node *currentNode = root;

    while(currentNode->left != NULL){
        currentNode = currentNode->left;
    }

    return currentNode->name;
}


// driver code
int main(){
	int count = 1;
	int minWeight;
	string name;
	int weight;
	Node* root = NULL;

    // getting root node information from the user
    cout << "Enter name and weight for person " << count << " (enter -1 -1 to exit): ";
	cin >> name >> weight;
	root = insert(root, name, weight, count);

    // getting user input for other nodes
	while (count < 15){
        cout << "Enter name and weight for person " << count+1 << " (enter -1 -1 to exit): ";
        cin >> name >> weight;

        // break condition if name and weight are -1
		if(name == "-1" && weight == -1){
			break;
        }
        
        // tracking the lowest weight 
		if(minWeight > weight){
		    minWeight = weight;
        }

        // inserting the node and incrementing the count 
		insert(root, name, weight, count);
		count++;
	}

    // program output to the screen
    cout << endl;
	cout << "Preorder Traversal: " << endl;
	preorder(root);
	cout << endl;
	cout << "Postorder Traversal: " << endl;
    postorder(root);
	cout << endl;
	cout << "Inorder Traversal: " << endl;
	inorder(root);
	cout << endl;
	cout << "Lowest weight in the tree: " << minWeight << endl;
	cout << "Height of the tree: " << getHeight(root)-1<< endl;
	cout << "Total number of leaves in the tree: " << getTotalLeaves(root) << endl;
	cout << "Total number of nodes in the tree: " << count << endl;
	cout << "First name in alphabetical order in the tree: " << getMinName(root) << endl;
	
    system("PAUSE");
}

/*
    SAMPLE OUTPUT:
        Enter name and weight for person 1 (enter -1 -1 to exit): LeBron 23
        Enter name and weight for person 2 (enter -1 -1 to exit): Kuzma 0
        Enter name and weight for person 3 (enter -1 -1 to exit): Davis 3
        Enter name and weight for person 4 (enter -1 -1 to exit): Caruso 4
        Enter name and weight for person 5 (enter -1 -1 to exit): Harrell 15
        Enter name and weight for person 6 (enter -1 -1 to exit): Gasol 14
        Enter name and weight for person 7 (enter -1 -1 to exit): Schroder 17
        Enter name and weight for person 8 (enter -1 -1 to exit): -1 -1

        Preorder Traversal: 
                Name: LeBron    Weight: 23
                Name: Kuzma     Weight: 0
                Name: Davis     Weight: 3
                Name: Caruso    Weight: 4
                Name: Harrell   Weight: 15
                Name: Gasol     Weight: 14
                Name: Schroder  Weight: 17

        Postorder Traversal: 
                Name: Caruso    Weight: 4
                Name: Gasol     Weight: 14
                Name: Harrell   Weight: 15
                Name: Davis     Weight: 3
                Name: Kuzma     Weight: 0
                Name: Schroder  Weight: 17
                Name: LeBron    Weight: 23

        Inorder Traversal:
                Name: Caruso    Weight: 4
                Name: Davis     Weight: 3
                Name: Gasol     Weight: 14
                Name: Harrell   Weight: 15
                Name: Kuzma     Weight: 0
                Name: LeBron    Weight: 23
                Name: Schroder  Weight: 17

        Lowest weight in the tree: 0
        Height of the tree: 4
        Total number of leaves in the tree: 3
        Total number of nodes in the tree: 7
        First name in alphabetical order in the tree: Caruso

*/

