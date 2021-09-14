int main()
{
	//creating an array of structs which is 
	//going to act as my hashtable.
    HashTable table; 


	Node* traverse;
	string fileLine;
	char* tokenizer;
	char* data;
	char* var;
	char* specialOperator;
	char* operation;
	char* operand;
	char storage[1024];
	int scope = 0;
	int commandCount;

	//declaring file object to read in
	ifstream borgFile("C:\\Users\\arifu\\Desktop\\CS41 HW\\Project 4\\input.txt", ios::in);
	if (borgFile.is_open())
	{
		//while there is text, iterate through every line of code/text.
		while (getline(borgFile, fileLine))
		{
			//need to copy the line we just got into a char array 
			//so that we can tokenize it without doing 'string surgery'.
			strcpy(storage, fileLine.c_str());
			//reads the first word into the tokenizer.
			tokenizer = strtok(storage, " ");
            // cout << tokenizer << endl;
			//if it's a COM statement, do nothing.
			if (strcmp(tokenizer, "COM") == 0) {}
			//if it's a START statement, increase the scope level.
			else if (strcmp(tokenizer, "START") == 0) { scope++; }
			//if it's a FINISH statement, decrease the scope level.
			else if (strcmp(tokenizer, "FINISH") == 0) { scope--; }
			//if it's a PRINT statement, print out the value.
			else if (strcmp(tokenizer, "PRINT") == 0)
			{
				//if there's a print statement that means there's more
				//than one word in the line (considering it's valid).
				//Therefore, we attempt to get all of them.

				var = strtok(NULL, " ");
				operation = strtok(NULL, " ");
				operand = strtok(NULL, " ");

				//if the second statement is NULL 
				//that must mean that the operation 
				//count has to be 1 and therefore it 
				//is a simple print. 
				if (operation == NULL)
					commandCount = 1;
				//otherwise there must be 3 commands,
				//a variable, an operator, and an operand 
				//in addition to the print statment (eg. PRINT ORANGE <-(VAR) * <-(OPERATOR) 2 <- (OPERAND))
				else
					commandCount = 3;

				//we invoke the function we wrote earlier to handle the rest. 
				table.processing(var, operation, operand, commandCount, scope);
			}
			//if it's VAR statement then we are inserting a Node.
			else if (strcmp(tokenizer, "VAR") == 0)
			{
				//we need to get the other values from the line. 
				var = strtok(NULL, " ");
				data = strtok(NULL, "=");
				//invokes the function to place this Node in
				//the proper hash table location.
				table.insert(var, data, scope);
			}
			//if it's none of the regualar statements then it's a special 
			//operator. Increment (++), Decrement (--), or Assignment (=)
			else
			{
				traverse = table.lookup(tokenizer, scope);
				//we have to find the operation we are doing.
				specialOperator = strtok(NULL, " ");
				//increment operation.
				if (strcmp(specialOperator, "++") == 0)
					traverse->data = traverse->data++;

				//decrement operation.
				else if (strcmp(specialOperator, "--") == 0)
					traverse->data = traverse->data--;

				//assignment operation.
				else if (strcmp(specialOperator, "=") == 0)
				{

					//extracting data.
					data = strtok(NULL, " ");
					//if the Node exists set the data equal to it.
					if (traverse != NULL)
						traverse->data = atoi(data);
				}
				//if all of this fails there must be an unrecognized error 
				//somewhere within the code. 
				else
					cout << "ERROR: UNRECOGNIZED OPERATOR" << endl;

			}

		}
	}
	system("PAUSE");
}

#define INT_MIN -2147483647
#define _CRT_SECURE_NO_WARNINGS
//need various libraries for 
//file io, math, and string manipulation.
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<math.h>


//picked a large enough prime number 
//for the table size. 
#define MAXSIZE 97

//this is purely for readability in the code
#define EMPTY NULL

using namespace std;

//node struct to create an array of
//nodes to act as a hash table
struct node
{
	int data;
	int scope;
	char var[1024];
	node* next;
};

//function to has a value for 
//positioning in the hash table
int Hash(char* variableName)
{
	int length = strlen(variableName);
	int hashValue = 0;

	//this could start at 1 because 
	//index of 0 would multiply to 0
	//but I kept it as is for convention.
	for (int i = 0; i < length; i++)
		hashValue += variableName[i] * i;

	return (hashValue = hashValue % MAXSIZE);
}

//function that inserts a node into the hash table
void insert(char* newVar, char* newData, int newScope, node** hashTable)
{
	//have to hash to find the mapped index
	int insertIndex = Hash(newVar);
	node* traverse;
	//setting up the node we are inserting.
	node* tmp = new node;
	strcpy(tmp->var, newVar);
	tmp->data = atoi(newData);
	tmp->scope = newScope;
	tmp->next = NULL;

	//if the space is not occupied 
	//place the node we set up earlier into it
	if (hashTable[insertIndex] == EMPTY)
		hashTable[insertIndex] = tmp;

	//otherwise, linear probe. However,
	//this specifically will go on forever
	//if the table is full because there is no
	//cycle check. But, as is, it works.
	else
	{
		traverse = hashTable[insertIndex];
		while (traverse->next != EMPTY)
			traverse = traverse->next;
		traverse->next = tmp;
	}
}

//function that returns a node or NULL value 
//based on whether the parameters match a node in the hashtable.
node* lookup(char* var, int scope, node** hashTable)
{
	//have to hash to 'reverse' lookup the node.
	int lookupIndex = Hash(var);
	node* traverse = hashTable[lookupIndex];
	//if the spot is not occupied it means 
	//there are no nodes with the characteristic specified.
	if (traverse == EMPTY)
	{
		//therefore, we return NULL.
		cout << var << " IS UNDEFINED" << endl;
		return NULL;
	}
	//otherwise, we will have to do other checks.
	else
	{
		//we use a traverse node to find out where specifically
		//the node we want to find is.
		//this loop puts the node in the correct position.
		while ((traverse->next != EMPTY) && (strcmp(traverse->var, var) != 0))
			traverse = traverse->next;

		//this check will ensure that the correct scope is taken into account
		//before returning the node we were looking up.
		if ((scope >= traverse->scope) && (strcmp(traverse->var, var) == 0))
			return traverse;
		//if there is no node that matches we will return NULL.
		else if (traverse->next == EMPTY)
		{
			cout << var << " IS UNDEFINED" << endl;
			return NULL;
		}
		//if there is a full cycle we will be booted from the function.
		else
			return NULL;
	}

}

void processing(char* var, char* operation, char* operand, int commandCount, int scope, node** hashTable)
{
	//finding out which node to utilize
	node* traverse = lookup(var, scope, hashTable);
	//making sure there actually is a node with the values specified.
	if (traverse != EMPTY)
	{
		//if there's only one command that
		//means it MUST be a print command
		if (commandCount == 1)
			//printing out the assigned value.
			cout << var << " IS " << traverse->data << endl;
		//the other scenario is that there are 3 commands, a variable, an operation, and a second variable (operand).
		else
		{
			//finding out what calulation to do, executing it, and then printing out the value.
			int calculation = INT_MIN;
			int intOperand = atoi(operand);
			if (strcmp(operation, "+") == 0) { calculation = traverse->data + intOperand; }
			else if (strcmp(operation, "-") == 0) { calculation = traverse->data - intOperand; }
			else if (strcmp(operation, "/") == 0) { calculation = traverse->data / intOperand; }
			else if (strcmp(operation, "*") == 0) { calculation = traverse->data * intOperand; }
			else if (strcmp(operation, "%") == 0) { calculation = traverse->data % intOperand; }
			else if (strcmp(operation, "^") == 0) { calculation = (int)pow(traverse->data,intOperand); }

			cout << var << " " << operation << " " << operand << " IS " << calculation << endl; 
		}
	}
}

int main()
{
	//creating an array of structs which is 
	//going to act as my hashtable.
	node* hashTable[MAXSIZE];

	//clearing out the hashTable so it is itiliziled to 'EMPTY'
	for (int i = 0; i < MAXSIZE; i++)
		hashTable[i] = EMPTY;

	//declaring various variables for use in 
	//string splicing, detection, processing, etc.
	node* traverse;
	string fileLine;
	char* tokenizer;
	char* data;
	char* var;
	char* specialOperator;
	char* operation;
	char* operand;
	char storage[1024];
	int scope = 0;
	int commandCount;

	//declaring file object to read in
	ifstream borgFile("C:\\Users\\arifu\\Desktop\\CS41 HW\\Project 4\\input.txt", ios::in);
    cout << "here " << endl;
	if (borgFile.is_open())
	{
		//while there is text, iterate through every line of code/text.
		while (getline(borgFile, fileLine))
		{
			//need to copy the line we just got into a char array 
			//so that we can tokenize it without doing 'string surgery'.
			strcpy(storage, fileLine.c_str());
			//reads the first word into the tokenizer.
			tokenizer = strtok(storage, " ");
            cout << tokenizer << endl;
			//if it's a COM statement, do nothing.
			if (strcmp(tokenizer, "COM") == 0) {}
			//if it's a START statement, increase the scope level.
			else if (strcmp(tokenizer, "START") == 0) { scope++; }
			//if it's a FINISH statement, decrease the scope level.
			else if (strcmp(tokenizer, "FINISH") == 0) { scope--; }
			//if it's a PRINT statement, print out the value.
			else if (strcmp(tokenizer, "PRINT") == 0)
			{
				//if there's a print statement that means there's more
				//than one word in the line (considering it's valid).
				//Therefore, we attempt to get all of them.

				var = strtok(NULL, " ");
				operation = strtok(NULL, " ");
				operand = strtok(NULL, " ");

				//if the second statement is NULL 
				//that must mean that the operation 
				//count has to be 1 and therefore it 
				//is a simple print. 
				if (operation == NULL)
					commandCount = 1;
				//otherwise there must be 3 commands,
				//a variable, an operator, and an operand 
				//in addition to the print statment (eg. PRINT ORANGE <-(VAR) * <-(OPERATOR) 2 <- (OPERAND))
				else
					commandCount = 3;

				//we invoke the function we wrote earlier to handle the rest. 
				processing(var, operation, operand, commandCount, scope, hashTable);
			}
			//if it's VAR statement then we are inserting a node.
			else if (strcmp(tokenizer, "VAR") == 0)
			{
				//we need to get the other values from the line. 
				var = strtok(NULL, " ");
				data = strtok(NULL, "=");
				//invokes the function to place this node in
				//the proper hash table location.
				insert(var, data, scope, hashTable);
			}
			//if it's none of the regualar statements then it's a special 
			//operator. Increment (++), Decrement (--), or Assignment (=)
			else
			{
				traverse = lookup(tokenizer, scope, hashTable);
				//we have to find the operation we are doing.
				specialOperator = strtok(NULL, " ");
				//increment operation.
				if (strcmp(specialOperator, "++") == 0)
					traverse->data = traverse->data++;

				//decrement operation.
				else if (strcmp(specialOperator, "--") == 0)
					traverse->data = traverse->data--;

				//assignment operation.
				else if (strcmp(specialOperator, "=") == 0)
				{

					//extracting data.
					data = strtok(NULL, " ");
					//if the node exists set the data equal to it.
					if (traverse != NULL)
						traverse->data = atoi(data);
				}
				//if all of this fails there must be an unrecognized error 
				//somewhere within the code. 
				else
					cout << "ERROR: UNRECOGNIZED OPERATOR" << endl;

			}

		}
	}
}

