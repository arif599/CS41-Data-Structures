#include<iostream>
//used for max. 
#include<algorithm>
using namespace std;

//node struct for use in our various functions.
struct node
{
	int weight;
	string name;
	node* left;
	node* right;
	node(int newWeight, string newName)
	{
		weight = newWeight;
		name = newName;
		left = NULL;
		right = NULL;
	}
};

//insert function
node* insert(node*root, int weight, string name, int count)
{
	//program specifies only 15 names and weights.
	//this if statements boots you out of the function if count is too high.
	if (count <= 15)
	{
		//creating a search node and a trialing node
		//to see where we need to fit in.
		node* temp = new node(weight, name);
		node* search = root;
		node* trail = NULL;
		while (search != NULL)
		{
			trail = search;
			if (temp->name > search->name)
				search = search->right;
			else
				search = search->left;
		}
		if (trail == NULL)
			trail = temp;
		else if (temp->name > trail->name)
			trail->right = temp;
		else
			trail->left = temp;
		return trail;
	}
	cout << "There are already 15 elements in the tree." << endl;

}

//function to print the tree in preorder.
void printPreorder(node* anyNode)
{
	if (anyNode == NULL)
		return;
	else
	{
		cout << "Name: " << anyNode->name << " Weight: " << anyNode->weight << endl;
		printPreorder(anyNode->left);
		printPreorder(anyNode->right);
	}
}

//function to print the tree in inorder.
void printInorder(node* anyNode)
{
	if (anyNode == NULL)
		return;
	else
	{
		printInorder(anyNode->left);
		cout << "Name: " << anyNode->name << " Weight: " << anyNode->weight << endl;
		printInorder(anyNode->right);
	}
}

//function to print the tree in postorder.
void printPostorder(node* anyNode)
{
	if (anyNode == NULL)
		return;
	else
	{
		printPostorder(anyNode->left);
		printPostorder(anyNode->right);
		cout << "Name: " << anyNode->name << " Weight: " << anyNode->weight << endl;
	}
}

//function to recursively find the height of the tree.
int findHeight(node* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int leftHeight = findHeight(root->left);
		int rightHeight = findHeight(root->right);
		return max(leftHeight, rightHeight) + 1;
	}
}

//function to search if an individual is in the tree.
//if they are then print their weight.
//otherwise, print an error to the user.
int searchWeight(node *root, string name)
{
	if (root == NULL)
	{
		//the value of -999 indicates flag. 
		cout << "There was no person matching with the name " << name << endl;
		return -999;
	}
	else if (root->name > name)
		return searchWeight(root->left, name);
	else if (root->name < name)
		return searchWeight(root->right, name);
	else
		return root->weight;
}

//function to find the number of leaves in the tree.
int findNumLeaves(node* root)
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return findNumLeaves(root->left) + findNumLeaves(root->right);
}

//THIS PROGRAM WILL ONLY WORK PROPERLY IF 1 OR MORE NODES ARE INSERTED.
//OTHERWISE IT WILL PRINT WEIRD AND GARBAGE VALUES IN THE OUTPUT!!!
int main()
{
	//specifies the number of nodes in the tree currently.
	int count = 1;
	//variable to find the first name alphabetically.
	string alphaName;
	//setting the lowestWeight to the lowest possible value.
	int lowestWeight = 0;
	//string name and weight for user input
	string name;
	int weight;
	//instantiating root and asking the user to populate it's data
	node* root = NULL;
	cout << "Enter a name and then a weight, enter -999 twice to exit: ";
	cin >> name >> weight;
	lowestWeight = weight;
	alphaName = name;
	root = insert(root, weight, name, count);
	//while loop to iteratively do this until they either quit or the number
	//of nodes is greater than 15.
	while (count < 15 && name != "-999" && weight != -999)
	{
		cout << "Enter another name and then a weight, enter -999 twice to exit: ";
		cin >> name >> weight;
		//I encountered an error when only 1 node was entered so I added this.
		//not the cleanest thing in the world but it gets the job done. 
		//I could definetly improve this program by adjusting the way the while loop operates.
		if (name == "-999" || weight == -999)
			break;
		//checking if lowestWeight needs to be updated
		if (lowestWeight > weight)
			lowestWeight = weight;
		//checking if alphaName needs to be updated
		//TECHNICALLY this isn't going through any nodes. 
		//but it will check every single user input entered.
		if (alphaName > name)
			alphaName = name;
		//inserting the node based on user input.
		insert(root, weight, name, count);
		//incrementing count because a new node was inserted.
		count++;
	}
	//printing the things I can. 
	cout << "Tree printed in Preorder: " << endl;
	printPreorder(root);
	cout << endl;
	cout << "Tree printed in Postorder: " << endl;
	printPostorder(root);
	cout << endl;
	cout << "Tree printed in Inorder: " << endl;
	printInorder(root);
	cout << endl;
	cout << "The lowest weight in the tree is: ";
	cout << lowestWeight << endl;
	//my findheight function is finnicky and doesn't follow the conventions 
	//of the class so I subtracted 1 in the main to get the "true height"
	cout << "The height of the tree is: ";
	cout << findHeight(root)-1 << endl;
	cout << "The number of leaves in the tree is: ";
	cout << findNumLeaves(root) << endl;
	cout << "The number of nodes in the tree is: " << count << endl;
	cout << "The first name in alphabetical order is: " << alphaName << endl;
	system("PAUSE");
	//this is where you can test the search functionality. 
	//I've tested it with the output you've given us as seen below in the output.
	/*
	cout << "Checking what MIKE'S weight is: " << searchWeight(root, "MIKE") << " lbs" << endl;
	cout << "Checking what JESSICA'S weight is: " << searchWeight(root, "JESSICA") << " lbs"  << endl;
	cout << "Checking what CARRY'S weight is: " << searchWeight(root, "CARRY") << " lbs" << endl;
	*/
	return 0;
}


/*
Enter a name and then a weight, enter -999 twice to exit: arif 5
Enter another name and then a weight, enter -999 twice to exit: sam 8
Enter another name and then a weight, enter -999 twice to exit: joe 9
Enter another name and then a weight, enter -999 twice to exit: hose 4
Enter another name and then a weight, enter -999 twice to exit: mike 11
Enter another name and then a weight, enter -999 twice to exit: -999 -999
Tree printed in Preorder: 
Name: arif Weight: 5
Name: sam Weight: 8
Name: joe Weight: 9
Name: hose Weight: 4
Name: mike Weight: 11

Tree printed in Postorder:
Name: hose Weight: 4
Name: mike Weight: 11
Name: joe Weight: 9
Name: sam Weight: 8
Name: arif Weight: 5

Tree printed in Inorder:
Name: arif Weight: 5
Name: hose Weight: 4
Name: joe Weight: 9
Name: mike Weight: 11
Name: sam Weight: 8

The lowest weight in the tree is: 4
The height of the tree is: 3
The number of leaves in the tree is: 2
The number of nodes in the tree is: 5
The first name in alphabetical order is: arif
*/